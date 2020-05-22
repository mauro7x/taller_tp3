#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

// ----------------------------------------------------------------------------
#include <string>

#include "Thread.h"

#include "Socket.h"
#include "Numbers.h"
#include "Results.h"

#include "SocketClosedException.h"
#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Accepter : public Thread {
    private:
        Socket socket;
        Numbers numbers;
        ProtectedResults& results;

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Accepter(const std::string& port, const std::string& numbers_filepath,
                 ProtectedResults& results);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Accepter(const Accepter&) = delete;
        Accepter& operator=(const Accepter&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        Accepter(Accepter&& other) = delete;
        Accepter& operator=(Accepter&& other) = delete;

        /**
         * Descripcion: lanza la ejecución del aceptador.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void run() override;

        /**
         * Descripcion: realiza el shutdown y el posterior close del socket
         * para dejar de recibir clientes.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void close();

        /** 
         * Descripcion: destructor.
        */
        ~Accepter();
}; 

// ----------------------------------------------------------------------------
#endif // __ACCEPTER_H__
