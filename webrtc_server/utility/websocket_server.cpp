#include "websocket_server.hpp"

#include <functional>

namespace websocketServer {

    socket_server::socket_server() {
        m_endpoint.set_error_channels(websocketpp::log::elevel::all);
        m_endpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
        m_endpoint.set_message_handler(std::bind(&socket_server::onMessage, this, std::placeholders::_1,std::placeholders::_2));
        m_endpoint.set_open_handler(std::bind(&socket_server::onNewConnection, this, std::placeholders::_1));
        m_endpoint.set_close_handler(std::bind(&socket_server::onCloseConnection, this, std::placeholders::_1));
        m_endpoint.init_asio();

        funcMap["sdpOffer"] = std::bind(&socket_server::handleSDPOffer, this, std::placeholders::_1);
    }

    socket_server::~socket_server() {
        for(const auto hdl : m_clients){
            m_endpoint.close(hdl, 0, "");
        }
        m_endpoint.stop_listening();
    }

    void socket_server::onNewConnection(websocketpp::connection_hdl hdl) {
        std::cout<<"new client came in\n";
        auto x = m_endpoint.get_con_from_hdl(hdl);
        m_clients.push_back(x);
    }

    void socket_server::onCloseConnection(websocketpp::connection_hdl hdl) {
        std::cout<<"client exited\n";
        m_clients.pop_back();
    }

    void socket_server::onMessage(websocketpp::connection_hdl hdl, server::message_ptr msg) {
        rapidjson::Document d;
        if(d.Parse(msg->get_payload().c_str()).HasParseError()) {
            std::cout<<"error parsing"<<std::endl;
            return;
        }
        assert(d.HasMember("header"));
        funcMap[d["header"].GetString()](d);
    }

    void socket_server::handleSDPOffer(const rapidjson::Document& d){
        std::cout<<"got an offer\n ";
    }

    void socket_server::run() {
        m_endpoint.listen(3000);
        m_endpoint.start_accept();
        m_endpoint.run();
    }
}