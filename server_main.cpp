/** TP3 - Taller de Programación - SERVIDOR
 * 
 * Alumno: Parafati, Mauro.
 * Padrón: 102749.
 * Año y cuatrimestre: 1C 2020.
 * Repositorio: https://github.com/mauro7x/taller_tp3
*/

// ----------------------------------------------------------------------------
#include <iostream>

#include "Results.h"
#include "ServerGame.h"
#include "Exception.h"


// just for test:
#include "Socket.h"
#define NUMBER 465

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << USAGE_ERROR_MSG << std::endl;
        return USAGE_ERROR;
    }

    std::string hostname = argv[1];
    std::string numbers_filepath = argv[2];

    try {
        // todo esto despues hay que ver donde lo hacemos, esto es para
        // probar funcionalidad.
        Results results;
        Socket accepter(hostname, 1);
        ServerGame game(accepter.accept(), results, NUMBER);
        game.run();

        accepter.shutdown();

    } catch (const Exception& e) {
        std::cerr << e.what() << "\n";
        return ERROR;
    } catch (...) {
        return ERROR;
    }

    return 0;
}

// ----------------------------------------------------------------------------

