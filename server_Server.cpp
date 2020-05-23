#include "Server.h"

// ----------------------------------------------------------------------------
// Métodos privados

void Server::_printResults() {
    std::cout << RESULTS_MSG(results.wins(), results.losses());
}

// ----------------------------------------------------------------------------
// API pública

Server::Server(const std::string& port, const std::string& numbers_filepath)
    : numbers(numbers_filepath), accepter(port, numbers, results) {}

void Server::run() {
    // hilo principal del servidor
    accepter.start();

    std::string input;
    do {
        std::getline(std::cin, input);
    } while (input != "q");

    accepter.close();
    accepter.join();

    _printResults();
}

Server::~Server() {}

// ----------------------------------------------------------------------------
