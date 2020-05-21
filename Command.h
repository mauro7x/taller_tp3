#ifndef __COMMAND_H__
#define __COMMAND_H__

// ----------------------------------------------------------------------------
#include <string>

#include "defs.h"
// ----------------------------------------------------------------------------

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
         * Parametros: -
        */
        Command(char id);

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
         * Descripcion: serializa el comando en un string, incluyendo el tipo
         * y variando el resto para cada comando.
         * Parametros: -
         * Retorno: string representando al comando.
        */
        //virtual std::string serialize() const = 0;

        /**
         * Descripcion: retorna el tipo del comando.
         * Parametros: -
         * Retorno: char identificador del comando.
        */
        char type() const;

        /**
         * Descripcion: se sobrecarga el operador () para la ejecución del
         * comando. Cada tipo de parametro redefine las acciones a ejecutar
         * cuando se use.
         * Parametros: -
         * Retorno -
        */
        virtual std::string operator()(unsigned short secret_number) const = 0;

        /** 
         * Descripcion: destructor.
        */
        virtual ~Command();
};

// ----------------------------------------------------------------------------
#endif // __COMMAND_H__
