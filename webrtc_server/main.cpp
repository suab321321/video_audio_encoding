
#define ASIO_STANDALONE

#include <iostream>
#include "utility/websocket_server.hpp"

int main() {
    websocketServer::socket_server server;
    server.run();
}




