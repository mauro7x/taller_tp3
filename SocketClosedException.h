#ifndef __SOCKET_CLOSED_EXCEPTION_H__
#define __SOCKET_CLOSED_EXCEPTION_H__

//-----------------------------------------------------------------------------
#include <string>

#include "Exception.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

class SocketClosedException : public Exception {
    public:
        explicit SocketClosedException(const std::string msg_error) noexcept :
                                       Exception(msg_error) {}
};

//-----------------------------------------------------------------------------
#endif // __SOCKET_CLOSED_EXCEPTION_H__
