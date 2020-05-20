#ifndef __GAME_PROXY_H__
#define __GAME_PROXY_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Exception.h"
#include "Protocol.h"
#include "Command.h"
#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// defines
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

/**
 * Documentar.
*/
class GameProxy {
    private:
        Protocol protocol;
        bool is_active;
        std::string last_answer;

        // atributos falsos para el proxy, se van a ir eliminando


        // Métodos privados
        void _checkIfFinished();

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        GameProxy();

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        GameProxy(const GameProxy&) = delete;
        GameProxy& operator=(const GameProxy&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        GameProxy(GameProxy&& other) = delete;
        GameProxy& operator=(GameProxy&& other) = delete;

        /**
         * Descripcion: verifica si el juego continua.
         * Parametros: -
         * Retorno: TRUE si el juego continua, FALSE si el juego terminó.
        */
        bool isActive() const;

        /**
         * Descripcion: envia un comando al servidor.
         * Parametros: comando a enviar.
         * Retorno: -
        */
        void send(const Command& cmd) const;

        /**
         * Descripcion: recibe la respuesta del servidor al ultimo
         * comando enviado y actualiza el valor is_active si el juego
         * termino.
         * Parametros: -
         * Retorno: -
        */
        void recv();

        /**
         * Descripcion: imprime la ultima respuesta del servidor.
         * Parametros: -
         * Retorno: -
        */
        void info() const;

        /** 
         * Descripcion: destructor.
        */
        ~GameProxy();
};

// ----------------------------------------------------------------------------
#endif // __GAME_PROXY_H__
