#include "Help.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Help::Help() : Command(HELP) {}


state Help::operator()(uint16_t secret_number, std::string& reply,
                       unsigned int& remaining_attempts) const {
    reply.clear();
    reply = HELP_MSG;
    return CONTINUE;
}


// ----------------------------------------------------------------------------
