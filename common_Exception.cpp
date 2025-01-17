#include "Exception.h"

//-----------------------------------------------------------------------------

Exception::Exception(const std::string msg_error) noexcept
    : msg_error(msg_error) {}

const char* Exception::what() const noexcept {
    return msg_error.c_str();
}

Exception::~Exception() noexcept {}

//-----------------------------------------------------------------------------
