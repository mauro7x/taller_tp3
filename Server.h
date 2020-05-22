#ifndef __SERVER_H__
#define __SERVER_H__

// ----------------------------------------------------------------------------
#include <iostream>

#include "Thread.h"
#include "Accepter.h"
#include "Results.h"

#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Server {
    private:
        Accepter accepter;
        ProtectedResults results;

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Server(const std::string& port, const std::string& numbers_filepath);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Server(const Server&) = delete;
        Server& operator=(const Server&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        Server(Server&& other) = delete;
        Server& operator=(Server&& other) = delete;

        /**
         * Descripcion: lanza la ejecución del servidor.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void run();

        /** 
         * Descripcion: destructor.
        */
        ~Server();
}; 




// ----------------------------------------------------------------------------
#endif // __SERVER_H__
