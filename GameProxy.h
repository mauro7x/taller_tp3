#ifndef __GAME_PROXY_H__
#define __GAME_PROXY_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Protocol.h"
#include "Command.h"
#include "defs.h"
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

        // server stuff:
        unsigned short int secret_number = 345;
        unsigned int remaining_attempts = 10;


        /**
         * Descripcion: chequea si el ultimo mensaje recibido fue de WIN o
         * de LOSS, y en caso afirmativo, se actualiza is_active a false.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void _checkIfFinished();

    public:
        /** 
         * Descripcion: constructor.
         * 
         * Parametros: -
         * 
         * >PUEDE LANZAR EXCEPCION.
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
         * 
         * Parametros: -
         * 
         * Retorno: TRUE si el juego continua, FALSE si el juego terminó.
        */
        bool isActive() const;

        /**
         * Descripcion: envia un comando al servidor y libera su memoria.
         * 
         * Parametros: comando a enviar.
         * 
         * Retorno: -
         * 
         * >PUEDE LANZAR EXCEPCION.
        */
        void send(Command* cmd); // agregar el const

        /**
         * Descripcion: recibe la respuesta del servidor al ultimo
         * comando enviado y actualiza el valor is_active si el juego
         * termino.
         * 
         * Parametros: -
         * 
         * Retorno: -
         * 
         * >PUEDE LANZAR EXCEPCION.
        */
        void recv();

        /**
         * Descripcion: imprime la ultima respuesta del servidor.
         * 
         * Parametros: -
         * 
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
