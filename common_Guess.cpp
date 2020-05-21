#include "Guess.h"

#include <iostream>

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Guess::Guess(unsigned short int value) : Command(GUESS), value(value) {}


unsigned short int Guess::number() const {
    return value;
}


std::string Guess::operator()(unsigned short secret_number) const {
    // GUESS ACTION
    
    return "Value: " + std::to_string(value) + ".";
}


// ----------------------------------------------------------------------------
