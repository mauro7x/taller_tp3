#include "ClientGame.h"

// ----------------------------------------------------------------------------
// Métodos privados

bool ClientGame::_continuePlaying() const {
    return !(last_answer == WIN_MSG || last_answer == LOSS_MSG);
}

// ----------------------------------------------------------------------------
// API pública

ClientGame::ClientGame(const std::string& hostname, const std::string& port)
    : protocol(hostname, port), command_streamer(std::cin) {}

void ClientGame::play() {
    while (_continuePlaying()) {
        protocol << command_streamer();
        protocol >> last_answer;
        std::cout << last_answer << std::endl;
    }
}

ClientGame::~ClientGame() {}

// ----------------------------------------------------------------------------
