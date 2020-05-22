#ifndef __SERVER_GAME_H__
#define __SERVER_GAME_H__

// ----------------------------------------------------------------------------
#include <string>

#include "ServerProtocol.h"
#include "Command.h"

#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ServerGame {
    private:
        ServerProtocol protocol;
        uint16_t secret_number;
        unsigned int remaining_attempts;

    public:
        /** 
         * Descripcion: constructor. Inicia el protocolo pasandole el fd
         * recibido, se supone correctamente inicializado por el Accepter.
         * 
         * Parametros: fd del socket peer, numero secreto, intentos restantes.
        */
        ServerGame(int fd, uint16_t secret_number);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        ServerGame(const ServerGame&) = delete;
        ServerGame& operator=(const ServerGame&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        ServerGame(ServerGame&& other) = delete;
        ServerGame& operator=(ServerGame&& other) = delete;

        /**
         * Cuando introduzcamos Threads, este metodo sera el hilo principal
         * de ejecución.
        */
        void run();
        
        /** 
         * Descripcion: destructor.
        */
        ~ServerGame();
};

// ----------------------------------------------------------------------------
#endif // __SERVER_GAME_H__
