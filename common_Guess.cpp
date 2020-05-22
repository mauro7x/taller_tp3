#include "Guess.h"

// ----------------------------------------------------------------------------
// Métodos privados

bool Guess::_isValid() const {
    if (value < MIN_ALLOWED_NUMBER || value > MAX_ALLOWED_NUMBER) {
        return false;
    }

    std::string s_value = std::to_string(value);
    char d1 = s_value[0], d2 = s_value[1], d3 = s_value[2];
    return !(d1 == d2 || d1 == d3 || d2 == d3);
}


size_t Guess::_countCorrectDigits(uint16_t secret_number) const {
    size_t correct_digits = 0;

    std::string s_value = std::to_string(value);
    std::string s_correct = std::to_string(secret_number);

    // digitos del intento:
    char d1 = s_value[0], d2 = s_value[1], d3 = s_value[2];    

    // digitos correctos:
    char c1 = s_correct[0], c2 = s_correct[1], c3 = s_correct[2];

    correct_digits += (int) (d1 == c1);
    correct_digits += (int) (d2 == c2);
    correct_digits += (int) (d3 == c3);

    return correct_digits;
}


size_t Guess::_countRegularDigits(uint16_t secret_number) const {
    size_t regular_digits = 0;

    std::string s_value = std::to_string(value);
    std::string s_correct = std::to_string(secret_number);

    // digitos del intento:
    char d1 = s_value[0], d2 = s_value[1], d3 = s_value[2];    

    // digitos correctos:
    char c1 = s_correct[0], c2 = s_correct[1], c3 = s_correct[2];

    regular_digits += (int) (d1 == c2 || d1 == c3);
    regular_digits += (int) (d2 == c1 || d2 == c3);
    regular_digits += (int) (d3 == c1 || d3 == c2);

    return regular_digits;
}


void Guess::_formatReply(std::string& reply, size_t correct_digits,
                          size_t regular_digits) const {
    reply.clear();

    if (correct_digits > 0 && regular_digits > 0) {
        reply = N_CORRECT_N_REGULAR_MSG(correct_digits, regular_digits);
    } else if (correct_digits > 0) {
        reply = N_CORRECT_MSG(correct_digits);
    } else if (regular_digits > 0) {
        reply = N_REGULAR_MSG(regular_digits);
    } else {
        reply = ALL_INCORRECT_MSG;
    }
}


// ----------------------------------------------------------------------------
// API pública

Guess::Guess(uint16_t value) : Command(GUESS), value(value) {}


uint16_t Guess::number() const {
    return value;
}


state Guess::operator()(uint16_t secret_number, std::string& reply,
                        unsigned int& remaining_attempts) const {
    if (!_isValid()) {
        reply.clear();
        reply = INVALID_NUMBER_ERROR_MSG;
        return CONTINUE;
    }

    if (value == secret_number) {
        reply.clear();
        reply = WIN_MSG;
        return WIN;
    }

    if (--remaining_attempts == 0) {
        reply.clear();
        reply = LOSS_MSG;
        return LOSS;
    }

    size_t correct_digits = _countCorrectDigits(secret_number);
    size_t regular_digits = _countRegularDigits(secret_number);
    _formatReply(reply, correct_digits, regular_digits);
    return CONTINUE;
}

// ----------------------------------------------------------------------------
