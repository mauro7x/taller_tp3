#include "Surrender.h"

// ----------------------------------------------------------------------------
// Métodos privados

// ----------------------------------------------------------------------------
// API pública

Surrender::Surrender() : Command(SURRENDER) {}

state Surrender::operator()(uint16_t secret_number, std::string& reply,
                            unsigned int& remaining_attempts) const {
    reply.clear();
    reply = LOSS_MSG;
    return LOSS;
}

// ----------------------------------------------------------------------------
