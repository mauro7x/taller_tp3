#include "Server.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Server::Server(const std::string& port, const std::string& numbers_filepath) :
               accepter(port, numbers_filepath, results) {}


void Server::run() {
    // hilo principal del servidor
    accepter.start();

    std::string input;
    do {
        std::getline(std::cin, input);
    } while (input != "q");

    accepter.close();
    accepter.join();
}


Server::~Server() {}


// ----------------------------------------------------------------------------
