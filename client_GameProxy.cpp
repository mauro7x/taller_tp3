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
    try {
        protocol << cmd;

        // proxy stuff (aca entra el server)
        Command* new_cmd = NULL;
        protocol >> new_cmd;
        // do stuff de server
        const Command& r = *new_cmd;
        protocol << r(200);
        delete new_cmd;
        


    } catch (const Exception& e) {
        throw e;
    }
}


void GameProxy::recv() {
    try {
        protocol >> last_answer;

    } catch (const Exception& e) {
        throw e;
    }

    // actualizar is_active
    _checkIfFinished();
}


void GameProxy::info() const {
    std::cout << last_answer << std::endl;
}


GameProxy::~GameProxy() {}


// ----------------------------------------------------------------------------
