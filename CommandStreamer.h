#ifndef __COMMAND_STREAMER_H__
#define __COMMAND_STREAMER_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <string>

#include "Exception.h"
#include "defs.h"

#include "Command.h"
#include "Guess.h"
#include "Help.h"
#include "Surrender.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// defines
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

/**
 * Documentar.
*/
class CommandStreamer {
    private:
        std::istream& stream;

        /**
         * Descripcion: intenta convertir un entero a un unsigned short int,
         * es decir un entero de 2 bytes. En caso de no poder, se lanza
         * una excepción.
         * Parametros: entero a convertir.
         * Retorno: entero convertido.
        */
        unsigned short int _convert(int n_received);

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: stream pasado por referencia.
         * 
         * NO SE HACE CARGO DE CERRARLO.
        */
        CommandStreamer(std::istream& stream);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        CommandStreamer(const CommandStreamer&) = delete;
        CommandStreamer& operator=(const CommandStreamer&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        CommandStreamer(CommandStreamer&& other) = delete;
        CommandStreamer& operator=(CommandStreamer&& other) = delete;

        /**
         * Descripcion: parsea la entrada del file apuntado por fd a un
         * comando, alocandolo en el HEAP y devolviendo su puntero.
         * Parametros: -
         * Retorno: puntero a comando en el HEAP.
         * 
         * SE DEBE LIBERAR LA MEMORIA DEL PUNTERO RECIBIDO.
        */
        Command* operator()();

        /** 
         * Descripcion: destructor.
        */
        ~CommandStreamer();
};

// ----------------------------------------------------------------------------
#endif // __COMMAND_STREAMER_H__
