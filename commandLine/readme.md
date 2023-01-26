In this example I will extract the raw output of a mp3 file, and save it as .pcm file, and then playing it back using aplay(cli utility) or audacity aap for linux.


1. Extracting the raw data value using ffmpeg

    cmd = "ffmpeg -i file_example_MP3_2MG.mp3 -f s32le -acodec pcm_s32le output.pcm -ac 2 -ar 44100"
        i      - inputFile
        f      - audio sample format (pcm_s32le means signed 32bit little endian)
        acodec - using audio stream
        ac     - no of channels
        ar     - sampling rate (in hertz)

        OR
         you can convert into pcm using this link https://www.360converter.com/conversion/audioConversion?curTargetFormat=pcm



2. Playing the raw .pcm file using aplay (alsa play)

    cmd = "aplay -c2 -fS32_LE -r22000 96565995edd996e3f5c6a28bcba84691.pcm"

    c - no of channels
    f - format
    r - sampling rate

    OR
     you can play using audacity software
