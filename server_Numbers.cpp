#include "Numbers.h"


#include <iostream>

// ----------------------------------------------------------------------------
// Métodos privados

void Numbers::_checkIfValid(const uint64_t& input_number) const {
    if (input_number < MIN_ALLOWED_NUMBER ||
        input_number > MAX_ALLOWED_NUMBER) {
        throw InputErrorException(OUT_OF_RANGE_INPUT_MSG);
    }

    std::string s_input_number = std::to_string(input_number);
    char d1 = s_input_number[0], d2 = s_input_number[1], d3 = s_input_number[2];

    if (d1 == d2 || d1 == d3 || d2 == d3) {
        throw InputErrorException(INVALID_FORMAT_INPUT_MSG);
    }
}


void Numbers::_parseNumbers(std::ifstream& file) {
    uint64_t input_number;
    uint16_t parsed_number;
    while (file >> input_number) {
        _checkIfValid(input_number);
        parsed_number = (uint16_t) input_number;
        numbers.push_back(parsed_number);
    }
}


// ----------------------------------------------------------------------------
// API pública

Numbers::Numbers(const std::string& filepath) {
    std::ifstream file;

    file.open(filepath);
    if (!file.is_open()) {
        throw InputErrorException("El archivo no se pudo abrir.");
    }

    _parseNumbers(file);
    it = numbers.begin();

    file.close();
    if (file.is_open()) {
        throw InputErrorException("El archivo no se pudo cerrar.");
    }
}


uint16_t Numbers::operator()() {
    uint16_t n = *(it++);
    if (it == numbers.end()) {
        it = numbers.begin();
    }
    return n;
}


Numbers::~Numbers() {}


// ----------------------------------------------------------------------------
