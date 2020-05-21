#include "GameProxy.h"

// ----------------------------------------------------------------------------
// Métodos privados

void GameProxy::_checkIfFinished() {
    if (last_answer == WIN_MSG || last_answer == LOSS_MSG) {
        is_active = false;
    }
}


// ----------------------------------------------------------------------------
// API pública

GameProxy::GameProxy() : is_active(true) {}


bool GameProxy::isActive() const {
    return is_active;
}


void GameProxy::send(Command* cmd) { // poner el const
    protocol << cmd;

    // proxy stuff (aca entra el server)
    {
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
    }
}


void GameProxy::recv() {
    protocol >> last_answer;
    _checkIfFinished();
}


void GameProxy::info() const {
    std::cout << last_answer << std::endl;
}


GameProxy::~GameProxy() {}


// ----------------------------------------------------------------------------
