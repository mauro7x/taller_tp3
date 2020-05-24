/** TP3 - Taller de Programación - SERVIDOR
 *
 * Alumno: Parafati, Mauro.
 * Padrón: 102749.
 * Año y cuatrimestre: 1C 2020.
 * Repositorio: https://github.com/mauro7x/taller_tp3
 */

// ----------------------------------------------------------------------------
#include <iostream>

#include "Exception.h"
#include "Server.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << USAGE_ERROR_MSG << std::endl;
        return SERVER_USAGE_ERROR;
    }

    std::string port = argv[1];
    std::string numbers_filepath = argv[2];

    try {
        Server server(port, numbers_filepath);
        server.run();
    } catch (const Exception& e) {
        std::cerr << e.what() << "\n";
        return SERVER_ERROR;
    } catch (...) {
        std::cerr << "Error desconocido." << '\n';
        return SERVER_ERROR;
    }

    return SERVER_SUCCESS;
}

// ----------------------------------------------------------------------------
