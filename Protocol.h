#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

// ----------------------------------------------------------------------------
#include <string>

#include "Command.h"

// PROXY INCLUDES (ir borrando):
#include <iostream>
#include "defs.h"

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// defines
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Protocol {
    private:


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
         * Parametros: comando a enviar.
         * Retorno: -
        */
        void operator<<(const Command& cmd) const;

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un comando.
         * Parametros: -
         * Retorno: comando a recibir
        */
        void operator>>(Command& cmd) const;

        /** 
         * Descripcion: sobrecarga del operador << para enviar un mensaje.
         * Parametros: string a enviar.
         * Retorno: -
        */
        void operator<<(const std::string& msg) const;

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un mensaje.
         * Parametros: -
         * Retorno: string a recibir
        */
        void operator>>(std::string& msg) const;


        /** 
         * Descripcion: destructor.
        */ 
        ~Protocol();
};

// ----------------------------------------------------------------------------
#endif // __PROTOCOL_H__
