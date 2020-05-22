#include "Accepter.h"

// ----------------------------------------------------------------------------
// Métodos privados

void Accepter::_acceptOneGame() {
    int peer = socket.accept();
    ServerGame* new_game = new ServerGame(peer, results, numbers());
    new_game->start();
    active_games.push_back(new_game);
}


void Accepter::_joinAndFreeFinishedGames() {
    std::vector<ServerGame*> tmp;
    std::vector<ServerGame*>::iterator it = active_games.begin();

    for (; it != active_games.end(); it++) {
        if ((*it)->isOver()) {
            (*it)->join();
            delete (*it);
        } else {
            tmp.push_back(*it);
        }
    }

    active_games.swap(tmp);
}


void Accepter::_joinGames() {
    std::vector<ServerGame*>::iterator it = active_games.begin();
    for (; it != active_games.end(); it++) {
        (*it)->join();
        delete (*it);
    }
}


void Accepter::_stopGames() {
    std::vector<ServerGame*>::iterator it = active_games.begin();
    for (; it != active_games.end(); it++) {
        (*it)->stop();
        (*it)->join();
        delete (*it);
    }
}


// ----------------------------------------------------------------------------
// API pública

Accepter::Accepter(const std::string& port,
                   const std::string& numbers_filepath,
                   ProtectedResults& results) :
                   socket(port, MAX_QUEUED_CLIENTS),
                   numbers(numbers_filepath), results(results) {}


void Accepter::run() {
    try {
        while (true) {
            _acceptOneGame();
            _joinAndFreeFinishedGames();
        }
    } catch (const SocketClosedException& e) {
        // Esperemos que terminen los juegos y salimos
        _joinGames();
    } catch (const Exception& e) {
        // Error grave: liberamos los recursos
        _stopGames();
        std::cerr << e.what() << '\n';
    } catch (...) {
        _stopGames();
        std::cerr << "Error desconocido." << '\n';
    }
}


void Accepter::close() {
    socket.shutdown();
    socket.close();
}


Accepter::~Accepter() {}


// ----------------------------------------------------------------------------
