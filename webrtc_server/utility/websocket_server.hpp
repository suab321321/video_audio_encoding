
#define ASIO_STANDALONE

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "rapidjson/document.h"
#include <unordered_map>
#include <functional>

namespace websocketServer {

    typedef websocketpp::server<websocketpp::config::asio> server;

    class socket_server {
        public:
            socket_server();
            ~socket_server();
            void messageHandler();
            void handleNewSDPOffer();
            void run();

        private:
            enum class headers{
                sdpOffer
            };
            void onNewConnection(websocketpp::connection_hdl hdl);
            void onCloseConnection(websocketpp::connection_hdl hdl);
            void handleSDPOffer(const rapidjson::Document&);
            void onMessage(websocketpp::connection_hdl hdl, server::message_ptr ptr);
            std::unordered_map<std::string, std::function<void(const rapidjson::Document&)> > funcMap;
            std::vector<std::shared_ptr<websocketpp::connection<websocketpp::config::asio>>> m_clients;
            server m_endpoint;
    };
}