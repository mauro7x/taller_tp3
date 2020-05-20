#include "Command.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Command::Command() {}


Command::Command(Command&& other) {
    // mover cosas
}


Command& Command::operator=(Command&& other) {
    // mover cosas

    return *this;
}


Command::~Command() {}


// ----------------------------------------------------------------------------
