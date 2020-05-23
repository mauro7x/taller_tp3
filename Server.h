#ifndef __SERVER_H__
#define __SERVER_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Accepter.h"
#include "Numbers.h"
#include "Results.h"
#include "Thread.h"
#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Server {
   private:
    ProtectedResults results;
    Numbers numbers;
    Accepter accepter;

    /**
     * Descripcion: imprime las estadisticas finales utilizando la macro
     * definida en defs.h, RESULTS_MSG.
     *
     * Parametros: -
     *
     * Retorno: -
     */
    void _printResults();

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
#endif  // __SERVER_H__
