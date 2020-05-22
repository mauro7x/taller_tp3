#ifndef __INPUT_ERROR_EXCEPTION_H__
#define __INPUT_ERROR_EXCEPTION_H__

//-----------------------------------------------------------------------------
#include "Exception.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

class InputErrorException : public Exception {
    public:
        explicit InputErrorException(const std::string msg_error) noexcept :
                                       Exception(msg_error) {}
};

//-----------------------------------------------------------------------------
#endif // __INPUT_ERROR_EXCEPTION_H__
