#include "CommandStreamer.h"

// ----------------------------------------------------------------------------
// Métodos privados

uint16_t CommandStreamer::_convert(int n_received) {
    if (n_received > MAX_POSSIBLE_NUMBER || n_received < MIN_POSSIBLE_NUMBER) {
        throw std::invalid_argument("El numero no se puede representar en "
                                    "2 bytes.");
    }
    return (uint16_t) n_received;
}

// ----------------------------------------------------------------------------
// API pública

CommandStreamer::CommandStreamer(std::istream& stream) : stream(stream) {}


Command* CommandStreamer::operator()() {
    std::string input;
    while(std::getline(stream, input)) {
        if (input == HELP_INPUT) {
            return new Help();

        } else if (input == SURRENDER_INPUT) {
            return new Surrender();

        } else {
            try {
                int n_received = std::stoi(input);
                uint16_t n = _convert(n_received);
                
                return new Guess(n);
            } catch (std::invalid_argument& e) {
                std::cout << UNKNOWN_COMMAND_ERROR_MSG << std::endl;
            } catch (...) {
                std::cout << UNKNOWN_COMMAND_ERROR_MSG << std::endl;
            }
        }
    }
    throw Exception("No hay mas comandos que procesar.");
}


CommandStreamer::~CommandStreamer() {}


// ----------------------------------------------------------------------------
