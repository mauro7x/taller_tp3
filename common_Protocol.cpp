#include "Protocol.h"

// ----------------------------------------------------------------------------
// Métodos privados

std::string Protocol::_serialize(Command* cmd) const {
    std::string serialized;
    char type = cmd->type();

    serialized += type;

    if (type == GUESS) {
        // Agregamos el numero en big endian
        unsigned short int number;
        number = ((Guess*) cmd)->number();
        number = htons(number);

        serialized += ((unsigned char*) &number)[0];
        serialized += ((unsigned char*) &number)[1];
    }

    return serialized;
}


// ----------------------------------------------------------------------------
// API pública

Protocol::Protocol() {}


// void Protocol::operator<<(const Command& cmd) const {
void Protocol::operator<<(Command* cmd) {
    // enviar un comando (client-side)
    std::string serialized = _serialize(cmd);
    delete cmd;

    try {
        // cambiar por enviar al socket
        cmd_serialized = serialized;

    } catch (const Exception& e) {
        throw e;
    }
}


void Protocol::operator>>(Command* &cmd) const {
    // recibir un comando (server-side)
    
    // cambiar por recibir 1 byte del socket
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


void Protocol::operator<<(const std::string& msg) { // poner const
    // enviar un mensaje (server-side)

    // cambiar por enviar msg por el socket
    answer = msg;

}

void Protocol::operator>>(std::string& msg) const {
    // recibir un mensaje (client-side)

    // cambiar por recibir msg del socket
    msg = answer;
}


Protocol::~Protocol() {}


// ----------------------------------------------------------------------------
