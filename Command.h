#ifndef __COMMAND_H__
#define __COMMAND_H__

// ----------------------------------------------------------------------------
#include <string>
#include <cstdint>

#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Tipos de comandos:
#define HELP 'h'
#define SURRENDER 's'
#define GUESS 'n'

// Flags de estado:
enum state {CONTINUE, WIN, LOSS};
// ----------------------------------------------------------------------------

/**
 * Documentar.
*/
class Command {
    private:
        char id;

    public:
        /** 
         * Descripcion: constructor.
         * 
         * Parametros: -
        */
        explicit Command(char id);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Command(const Command&) = delete;
        Command& operator=(const Command&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        Command(Command&& other) = delete;
        Command& operator=(Command&& other) = delete;

        /**
         * Descripcion: retorna el tipo del comando.
         * 
         * Parametros: -
         * 
         * Retorno: char identificador del comando.
        */
        char type() const;

        /**
         * Descripcion: se sobrecarga el operador () para la ejecución del
         * comando. Cada tipo de parametro redefine las acciones a ejecutar
         * cuando se use. Se actualiza reply con información.
         * 
         * Parametros: numero secreto a adivinar, respuesta a llenar pasada
         * por referencia, intentos restantes pasados por referencia.
         * 
         * Retorno: CONTINUE == continuar.
         *          WIN == el cliente gano.
         *          LOSS == el cliente perdió.
        */
        virtual state operator()(uint16_t secret_number,
                               std::string& reply,
                               unsigned int& remaining_attempts) const = 0;

        /** 
         * Descripcion: destructor.
        */
        virtual ~Command();
};

// ----------------------------------------------------------------------------
#endif // __COMMAND_H__
