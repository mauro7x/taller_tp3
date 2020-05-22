#include "ClientProtocol.h"

// ----------------------------------------------------------------------------
// Métodos privados

std::string ClientProtocol::_serialize(Command* cmd) const {
    std::string serialized;
    char type = cmd->type();

    serialized += type;

    if (type == GUESS) {
        // Agregamos el numero en big endian
        uint16_t number;
        number = ((Guess*) cmd)->number();
        number = htons(number);

        serialized += ((unsigned char*) &number)[0];
        serialized += ((unsigned char*) &number)[1];
    }

    return serialized;
}


// ----------------------------------------------------------------------------
// API pública

ClientProtocol::ClientProtocol(const std::string& hostname, const std::string& port) :
                   socket(hostname, port) {}


void ClientProtocol::operator<<(Command* cmd) const {
    std::string serialized = _serialize(cmd);
    delete cmd;

    socket.send(serialized.c_str(), serialized.size());
}


void ClientProtocol::operator>>(std::string& msg) const {
    // RECIBIR MENSAJE DEL SOCKET

}



ClientProtocol::~ClientProtocol() {}


// ----------------------------------------------------------------------------
