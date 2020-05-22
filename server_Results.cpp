#include "Results.h"

// ----------------------------------------------------------------------------
// Métodos privados


// ----------------------------------------------------------------------------
// API pública

Results::Results() : n_wins(0), n_losses(0) {}


void Results::addWin() {
    std::unique_lock<std::mutex> l(m);
    n_wins++;
}


void Results::addLoss() {
    std::unique_lock<std::mutex> l(m);
    n_losses++;
}


unsigned int Results::wins() {
    std::unique_lock<std::mutex> l(m);
    return n_wins;
}


unsigned int Results::losses() {
    std::unique_lock<std::mutex> l(m);
    return n_losses;
}


Results::~Results() {}

// ----------------------------------------------------------------------------
