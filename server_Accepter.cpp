#include "Accepter.h"

// ----------------------------------------------------------------------------
// Métodos privados

#include <iostream>

// ----------------------------------------------------------------------------
// API pública

Accepter::Accepter(const std::string& port,
                   const std::string& numbers_filepath,
                   ProtectedResults& results) :
                   socket(port, MAX_QUEUED_CLIENTS),
                   numbers(numbers_filepath), results(results) {}


void Accepter::run() {
    // hilo aceptador
    int peer;

    try {
        while(true) {
            peer = socket.accept();
            std::cout << "Se conecto un cliente! peer:" << peer << "\n";
            // crear el game y ponerlo en la lista

            // for para deletear clientes muertos

        }
    } catch (const SocketClosedException& e) {
        // El socket se cerró: esperemos que terminen
        // los juegos y salimos

    } catch (const Exception& e) {
        // Error grave: liberamos los recursos
        
    }
}


void Accepter::close() {
    socket.shutdown();
    socket.close();
}


Accepter::~Accepter() {}


// ----------------------------------------------------------------------------
