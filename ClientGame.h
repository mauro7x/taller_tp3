#ifndef __CLIENT_GAME_H__
#define __CLIENT_GAME_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "CommandStreamer.h"
#include "ClientProtocol.h"
#include "Command.h"

#include "ClosedSocketException.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ClientGame {
    private:
        ClientProtocol protocol;
        CommandStreamer command_streamer;
        std::string last_answer;

        /**
         * Descripcion: chequea si el juego sigue activo en base a la ultima
         * respuesta recibida del servidor (si es WIN o LOSS, se termina).
         * 
         * Parametros: -
         * 
         * Retorno: TRUE si el juego sigue, FALSE si terminó.
        */
        bool _continuePlaying() const;

    public:
        /** 
         * Descripcion: constructor. Inicia el protocolo pasandole el hostname
         * y el puerto recibido para que se conecte.
         * 
         * Parametros: hostname y puerto del servidor al que conectarse.
        */
        ClientGame(const std::string& hostname, const std::string& port);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        ClientGame(const ClientGame&) = delete;
        ClientGame& operator=(const ClientGame&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        ClientGame(ClientGame&& other) = delete;
        ClientGame& operator=(ClientGame&& other) = delete;

        /**
         * Descripcion: lanza la ejecución del juego.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void play();
        
        /** 
         * Descripcion: destructor.
        */
        ~ClientGame();
};

// ----------------------------------------------------------------------------
#endif // __CLIENT_GAME_H__
