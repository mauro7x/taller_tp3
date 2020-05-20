#include "CommandStreamer.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

CommandStreamer::CommandStreamer(FILE* fd) : fd(fd) {}


Command CommandStreamer::operator()() {
    // parsear un comando
    Command new_cmd;

    // lo devolvemos
    return new_cmd;
}

CommandStreamer::~CommandStreamer() {}


// ----------------------------------------------------------------------------
