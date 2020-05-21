#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

// ----------------------------------------------------------------------------
#include <string>
#include <arpa/inet.h>

#include "Exception.h"

#include "Command.h"
#include "Guess.h"
#include "Surrender.h"
#include "Help.h"

// PROXY INCLUDES (ir borrando):
#include <iostream>

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// defines
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Protocol {
    private:

        // proxy lies:
        std::string cmd_serialized;
        std::string answer;


        /**
         * Descripcion: realiza la serialización correspondiente desde
         * un puntero a comando a un string serializado listo para enviar.
         * Parametros: puntero a comando.
         * Retorno: comando serializado en string.
        */
        std::string _serialize(Command* cmd) const;

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Protocol();

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Protocol(const Protocol&) = delete;
        Protocol& operator=(const Protocol&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        Protocol(Protocol&& other) = delete;
        Protocol& operator=(Protocol&& other) = delete;

        /** 
         * Descripcion: sobrecarga del operador << para enviar un comando.
         * Parametros: puntero al comando a enviar.
         * Retorno: -
         * 
         * LIBERA LA MEMORIA APUNTADA POR EL PUNTERO RECIBIDO.
        */
        void operator<<(Command* cmd); // falta agregar const

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un comando.
         * Aloca la memoria necesaria para el comando recibido en el puntero
         * recibido por parametro.
         * Parametros: puntero al comando a recibir.
         * Retorno: -
         * 
         * SE DEBE LIBERAR LA MEMORIA APUNTADA POR EL PUNTERO RETORNADO
        */
        void operator>>(Command* &cmd) const;

        /** 
         * Descripcion: sobrecarga del operador << para enviar un mensaje.
         * Parametros: string a enviar pasado por referencia.
         * Retorno: -
        */
        void operator<<(const std::string& msg); // poner const

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un mensaje.
         * Parametros: string a recibir pasado por referencia
         * Retorno: -
        */
        void operator>>(std::string& msg) const;


        /** 
         * Descripcion: destructor.
        */ 
        ~Protocol();
};

// ----------------------------------------------------------------------------
#endif // __PROTOCOL_H__
