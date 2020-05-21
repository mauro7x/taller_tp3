#include "CommandStreamer.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

CommandStreamer::CommandStreamer(FILE* fd) : fd(fd) {}


Command* CommandStreamer::operator()() {
    // parsear un comando

    return new Guess(87);
}

CommandStreamer::~CommandStreamer() {}


// ----------------------------------------------------------------------------
