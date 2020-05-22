/** TP3 - Taller de Programación - CLIENTE
 *
 * Alumno: Parafati, Mauro.
 * Padrón: 102749.
 * Año y cuatrimestre: 1C 2020.
 * Repositorio: https://github.com/mauro7x/taller_tp3
 */

// ----------------------------------------------------------------------------
#include <iostream>

#include "ClientGame.h"
#include "Exception.h"
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
        ClientGame game(hostname, port);
        game.play();
    } catch (const Exception& e) {
        std::cerr << e.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Error desconocido." << '\n';
        return ERROR;
    }

    return 0;
}

// ----------------------------------------------------------------------------
