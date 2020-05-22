#include "ServerProtocol.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

ServerProtocol::ServerProtocol(const int fd) : peer(fd) {}


void ServerProtocol::operator>>(Command* &cmd) const {
    char type;
    if (!peer.recv(&type, sizeof(type))) {
        throw ClosedSocketException("El cliente cerró el socket.");
    }

    switch (type) {
        case GUESS: {
            uint16_t number, be_number;
            if (!(peer >> be_number)) {
                throw ClosedSocketException("El cliente cerró el socket.");
            }
            number = ntohs(be_number);
            cmd = new Guess(number);
            break;
        }
        
        case HELP: {
            cmd = new Help();
            break;
        }

        case SURRENDER: {
            cmd = new Surrender();
            break;
        }
    }
}


void ServerProtocol::operator<<(const std::string& msg) const {
    uint16_t be_len, len = msg.size();
    be_len = htons(len);
    peer << be_len;
    peer << msg;
}


void ServerProtocol::stop() {
    peer.shutdown();
    peer.close();
}


ServerProtocol::~ServerProtocol() {
    peer.shutdown();
}


// ----------------------------------------------------------------------------
