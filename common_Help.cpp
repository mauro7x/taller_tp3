#include "Help.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Help::Help() : Command(HELP) {}


std::string Help::operator()(unsigned short secret_number) const {
    // HELP ACTION
    
    return HELP_MSG;
}


// ----------------------------------------------------------------------------
