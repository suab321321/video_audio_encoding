cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}")

set(SRC_FILES "utility/websocket_server.cpp")
set(HEADER_FILES "utility/websocket_server.hpp")

add_executable(webrtc_server main.cpp ${SRC_FILES} ${HEADER_FILES})

find_package(websocketpp REQUIRED)
find_package(RapidJSON REQUIRED)
find_library(webrtc_lib "libwebrtc.a" "/home/abhinav/webrtc_checkout/src/out" REQUIRED)
target_include_directories(webrtc_server PUBLIC ${WEBSOCKETPP_INCLUDE_DIR} ${RapidJSON_INCLUDE_DIRS})
target_include_directories(webrtc_server PUBLIC "/home/abhinav/webrtc_checkout/src/")