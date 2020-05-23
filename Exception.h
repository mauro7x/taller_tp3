#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

//-----------------------------------------------------------------------------
#include <exception>
#include <string>
//-----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Codigos de retorno
#define CLIENT_ERROR 0
#define CLIENT_USAGE_ERROR 0

#define SERVER_ERROR 1
#define SERVER_USAGE_ERROR 1
// ----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

class Exception : public std::exception {
   private:
    std::string msg_error;

   public:
    /**
     * Descripcion: constructor.
     *
     * Parametros: mensaje de error.
     */
    explicit Exception(const std::string msg_error) noexcept;

    /**
     * Descripcion: devuelve el mensaje de error.
     *
     * Parametros: -
     *
     * Retorno: mensaje de error.
     *
     * No hay que ocuparse del puntero recibido.
     */
    virtual const char* what() const noexcept;

    /**
     * Descripcion: destructor.
     */
    virtual ~Exception() noexcept;
};

//-----------------------------------------------------------------------------
#endif  // __EXCEPTION_H__
