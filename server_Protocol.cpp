#include "ServerProtocol.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

ServerProtocol::ServerProtocol(const int fd) : peer(fd) {}


void ServerProtocol::operator>>(Command* &cmd) const {

    // CAMBIAR PARA RECIBIR 1 CHAR DEL SOCKET
    std::string cmd_serialized;

    char type = cmd_serialized[0];

    switch (type) {
        case GUESS: {
            unsigned short int number;
            unsigned short int be_number;

            // cambiar por recibir un unsigned short int del socket
            ((unsigned char*) &be_number)[0] = cmd_serialized[1];
            ((unsigned char*) &be_number)[1] = cmd_serialized[2];
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
    // ENVIAR MENSAJE AL SOCKET

}


ServerProtocol::~ServerProtocol() {
    peer.shutdown();
}


// ----------------------------------------------------------------------------
