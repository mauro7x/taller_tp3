#include "ClientProtocol.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

ClientProtocol::ClientProtocol(const std::string& hostname, const std::string& port) :
                   socket(hostname, port) {}


void ClientProtocol::operator<<(Command* cmd) const {
    uint16_t be_number;
    char type = cmd->type();
    
    if (type == GUESS) {
        uint16_t number = ((Guess*) cmd)->number();
        be_number = htons(number);
    }

    delete cmd;

    socket << type;
    if (type == GUESS) {
        socket << be_number;
    }
}


void ClientProtocol::operator>>(std::string& msg) const {
    uint16_t len, be_len;
    if (!(socket >> be_len)) {
        throw SocketClosedException("El servidor cerró el socket.");
    }
    len = ntohs(be_len);

    msg.clear();
    msg.reserve(len);

    char c;
    for (uint16_t i = 0; i < len; i++) {
        if (!socket.recv(&c, sizeof(char))) {
            throw SocketClosedException("El servidor cerró el socket.");
        }
        msg += c;
    }
}


void ClientProtocol::stop() {
    socket.shutdown();
    socket.close();
}


ClientProtocol::~ClientProtocol() {}


// ----------------------------------------------------------------------------
