#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

#include "Thread.h"
#include "SocketClosedException.h"
#include "defs.h"

#include "Socket.h"
#include "Numbers.h"
#include "Results.h"
#include "ServerGame.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Accepter : public Thread {
    private:
        Socket socket;
        Numbers numbers;
        ProtectedResults& results;
        std::vector<ServerGame*> active_games;


        /**
         * Descripcion: acepta un nuevo cliente y pone su juego a correr, lo
         * agrega al vector de games activos.
         * 
         * Parametros: -
         * 
         * Retorno: -
         * 
         * Cuando se cierre el server, se lanzara la excepción
         * SocketClosedException.
        */
        void _acceptOneGame();

        /**
         * Descripcion: recorre el vector de games activos en busqueda de games
         * que hayan terminado su ejecución. A estos games, se les hace un join
         * NO BLOQUEANTE y se libera su memoria.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void _joinAndFreeFinishedGames();

        /**
         * Descripcion: joinea los games activos.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void _joinGames();

        /**
         * Descripcion: cierra forzosamente los games activos.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void _stopGames();

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
