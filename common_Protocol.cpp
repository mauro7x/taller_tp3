#include "Protocol.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Protocol::Protocol() {}


void Protocol::operator<<(const Command& cmd) const {
    // enviar un comando (client-side)
    std::cout << "Se envía un comando que aun no existe jeje" << std::endl;
}


void Protocol::operator>>(Command& cmd) const {
    // recibir un comando (server-side)

}


void Protocol::operator<<(const std::string& msg) const {
    // enviar un mensaje (server-side)

}

void Protocol::operator>>(std::string& msg) const {
    // recibir un mensaje (client-side)
    msg.clear();
    msg = WIN_MSG;
}


Protocol::~Protocol() {}


// ----------------------------------------------------------------------------
