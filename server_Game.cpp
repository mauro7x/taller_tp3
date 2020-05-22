#include "ServerGame.h"

// ----------------------------------------------------------------------------
// Métodos privados

// ----------------------------------------------------------------------------
// API pública

ServerGame::ServerGame(int fd, ProtectedResults& results,
                       uint16_t secret_number)
    : protocol(fd),
      results(results),
      secret_number(secret_number),
      remaining_attempts(ATTEMPTS),
      is_running(true) {}

void ServerGame::run() {
    try {
        Command* new_cmd = NULL;
        bool continuePlaying = true;
        state s;
        std::string reply;

        while (continuePlaying) {
            protocol >> new_cmd;
            const Command& r = *new_cmd;
            s = r(secret_number, reply, remaining_attempts);

            switch (s) {
                case WIN: {
                    results.addWin();
                    continuePlaying = false;
                    break;
                }

                case LOSS: {
                    results.addLoss();
                    continuePlaying = false;
                    break;
                }

                case CONTINUE: {
                    break;
                }
            }

            protocol << reply;
            delete new_cmd;
        }
    } catch (const Exception& e) {
        std::cerr << e.what() << '\n';
    } catch (...) {
        std::cerr << "Error desconocido." << '\n';
    }

    is_running = false;
}

bool ServerGame::isOver() {
    return !is_running;
}

void ServerGame::stop() {
    protocol.stop();
}

ServerGame::~ServerGame() {}

// ----------------------------------------------------------------------------
