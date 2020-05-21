/** TP3 - Taller de Programación - CLIENTE
 * 
 * Alumno: Parafati, Mauro.
 * Padrón: 102749.
 * Año y cuatrimestre: 1C 2020.
 * Repositorio: https://github.com/mauro7x/taller_tp3
*/

// ----------------------------------------------------------------------------
#include <iostream>

#include "defs.h"
#include "Exception.h"

#include "CommandStreamer.h"
#include "GameProxy.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cout << USAGE_ERROR_MSG << std::endl;
        return USAGE_ERROR;
    }

    std::string hostname = argv[1];
    std::string port = argv[2];

    try {
        CommandStreamer command_streamer(std::cin);
        GameProxy game;

        while (game.isActive()) {
            game.send(command_streamer());
            game.recv();
            game.info();
        }

    } catch (const Exception& e) {
        std::cerr << e.what() << "\n";
        return ERROR;
    } catch (...) {
        return ERROR;
    }

    return 0;
}

// ----------------------------------------------------------------------------

