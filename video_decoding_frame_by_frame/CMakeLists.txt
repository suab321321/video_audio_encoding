cmake_minimum_required(VERSION 3.12)

add_executable(video_decode main.cpp)

find_library(avformat libavformat.so REQUIRED)
find_library(avcodec libavcodec.so REQUIRED)
find_library(avutil libavutil.so REQUIRED)
find_library(sdl libSDL2.so REQUIRED)

target_link_libraries(video_decode ${avformat} ${avcodec} ${avutil} ${sdl})