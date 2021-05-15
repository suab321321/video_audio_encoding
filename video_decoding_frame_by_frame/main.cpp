#include <stdio.h>
#include <SDL2/SDL.h>
extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
}

#define screen_height 640
#define screen_width 1280

SDL_Window* window = NULL;
SDL_Texture* texture = NULL;
SDL_Renderer* renderer = NULL;

void initialize_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("Error initializing sdl \n");
        exit(-1);
    }
    window = SDL_CreateWindow("Frame",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screen_width,screen_height,0);
    if(!window) {
        printf("error crearting windows\n");
        exit(-1);
    }
    renderer = SDL_CreateRenderer(window,-1,0);
    if(!renderer) {
        printf("Error creating renderer\n");
        exit(-1);
    }
    texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_YV12,SDL_TEXTUREACCESS_STREAMING,screen_width,screen_height);
    if(!texture) {
        printf("Error creating texture\n");
        exit(-1);
    }
}


void clean_SDL() {
    SDL_DestroyWindow(window);
}


void display_frame(AVFrame* frame) {
    SDL_UpdateYUVTexture(
        texture,
        NULL,
        frame->data[0],
        frame->linesize[0],
        frame->data[1],
        frame->linesize[1],
        frame->data[2],
        frame->linesize[2]
    );
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}


int main(int argc, char** argv) {

    // av_register_all();
    initialize_SDL();

    AVFormatContext* avfmtCtx = NULL;
    
    if(avformat_open_input(&avfmtCtx,argv[1],NULL,0) == -1) {
        printf("Cant open input file\n");
        return -1;
    }
    if (avformat_find_stream_info(avfmtCtx,NULL) < 0) {
        printf("Error finding stream info\n");
    }

    av_dump_format(avfmtCtx, 0, argv[1], 0);

    int videoStream = -1;

    AVCodecParameters* avcparams = NULL;
    for(int i = 0; i < avfmtCtx->nb_streams; i++) {
        avcparams = avfmtCtx->streams[i]->codecpar;
        if(avcparams && avcparams->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
            break;
        }
    }
    AVCodec* avcodec = avcodec_find_decoder(avcparams->codec_id);
    AVCodecContext* avctx = avcodec_alloc_context3(avcodec);
    avcodec_parameters_to_context(avctx,avcparams);
    avcodec_open2(avctx, avcodec,NULL);

    AVPacket* avpkt = av_packet_alloc();
    AVFrame* avframe = av_frame_alloc();

    // For video, the packet contains
    // * exactly one frame

    // or audio, it contains an integer number of frames if each
    // * frame has a known fixed size (e.g. PCM or ADPCM data). If the audio frames
    // * have a variable size (e.g. MPEG audio), then it contains one frame

    while(av_read_frame(avfmtCtx, avpkt) == 0) {
        if (avpkt->stream_index == videoStream) {
            int send_pkt_ret = avcodec_send_packet(avctx,avpkt);
            if (send_pkt_ret == AVERROR(EAGAIN)) 
                continue;
            else if (send_pkt_ret < 0) {
                printf("error reading packet\n");
                break;
            }
            else {
                int receive_frame_ret = avcodec_receive_frame(avctx,avframe);
                if (receive_frame_ret == AVERROR(EAGAIN)) continue;
                else if (receive_frame_ret < 0) {
                    printf("error in avcodec_receive_frame\n");
                    return -1;
                }
                else{
                    int t = 1;
                    display_frame(avframe);
                }
            }
        }
        //resetting the fields of frame and packet and unreferencing the buffer inside them
        av_packet_unref(avpkt);
        av_frame_unref(avframe);
    }

    //freeing the allocated memory by frame and packet
    av_packet_free(&avpkt);
    av_frame_free(&avframe);
}