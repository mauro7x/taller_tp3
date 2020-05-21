#ifndef __COMMAND_STREAMER_H__
#define __COMMAND_STREAMER_H__

// ----------------------------------------------------------------------------
#include <fstream>

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
        FILE* fd;

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: file descriptor del que streamear comandos.
         * 
         * NO SE HACE CARGO DE CERRARLO.
        */
        CommandStreamer(FILE* fd);

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
