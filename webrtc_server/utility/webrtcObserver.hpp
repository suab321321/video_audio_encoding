
#pragma once

#include <api/peer_connection_interface.h>
#include <api/scoped_refptr.h>

#include <functional>

class PeerConnectionObserver : public webrtc::PeerConnectionObserver {
    public:
        PeerConnectionObserver(std::function<void(webrtc::rtc::scoped_refptr<webrtc::>)> onDataChannel, 
                                std::function<void()> onIceCandidate) {
            m_onDataChannel = onDataChannel;
            m_onIceCandidate = onIceCandidate;
        }
        void OnDataChannel();
        void OnIceGatheringChange();

    private:
        std::function<void()> m_onDataChannel;
        std::function<void()> m_onIceCandidate;
};

class CreateSessionDescriptionOffer : public webrtc::CreateSessionDescriptionObserver {
    public:
        
};

