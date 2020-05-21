#include "ServerGame.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

ServerGame::ServerGame(int fd, unsigned short int secret_number) :
                       protocol(fd), secret_number(secret_number),
                       remaining_attempts(ATTEMPTS) {}


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


void ServerGame::run() {
    
    std::cout << "Ejecución del server terminando!\n";
}

ServerGame::~ServerGame() {}

// ----------------------------------------------------------------------------
