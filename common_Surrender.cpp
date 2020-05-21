#include "Surrender.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Surrender::Surrender() : Command(SURRENDER) {}


std::string Surrender::operator()(unsigned short secret_number) const {
    // SURRENDER ACTION
    
    return LOSS_MSG;    
}


// ----------------------------------------------------------------------------
