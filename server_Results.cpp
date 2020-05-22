#include "Results.h"

// ----------------------------------------------------------------------------
// Métodos privados

// ----------------------------------------------------------------------------
// API pública

ProtectedResults::ProtectedResults() : n_wins(0), n_losses(0) {}

void ProtectedResults::addWin() {
    std::unique_lock<std::mutex> l(m);
    n_wins++;
}

void ProtectedResults::addLoss() {
    std::unique_lock<std::mutex> l(m);
    n_losses++;
}

unsigned int ProtectedResults::wins() {
    std::unique_lock<std::mutex> l(m);
    return n_wins;
}

unsigned int ProtectedResults::losses() {
    std::unique_lock<std::mutex> l(m);
    return n_losses;
}

ProtectedResults::~ProtectedResults() {}

// ----------------------------------------------------------------------------
