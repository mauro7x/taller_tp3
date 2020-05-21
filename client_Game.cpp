#include "ClientGame.h"

// ----------------------------------------------------------------------------
// Métodos privados

bool ClientGame::_continuePlaying() const {
    if (last_answer == WIN_MSG || last_answer == LOSS_MSG) {
        return false;
    }

    return true;
}


// ----------------------------------------------------------------------------
// API pública

ClientGame::ClientGame(const std::string& hostname, const std::string& port) :
                     protocol(hostname, port), command_streamer(std::cin) {}


/* SERVER STUFF
    Command* new_cmd = NULL;
    protocol >> new_cmd;
    
    // do stuff de server
    const Command& r = *new_cmd;
    state s;
    std::string reply;

    s = r(secret_number, reply, remaining_attempts);

    switch (s) {
        case WIN: {
            // aumentar contador de victorias
            break;
        }

        case LOSS: {
            // aumentar contador de derrotas
            break;
        }

        case CONTINUE: {
            break;
        }
    }

    protocol << reply;
    delete new_cmd;
*/


void ClientGame::play() {
    while (_continuePlaying()) {
        protocol << command_streamer();
        protocol >> last_answer;
        std::cout << last_answer << std::endl;
    }
}

ClientGame::~ClientGame() {}

// ----------------------------------------------------------------------------
