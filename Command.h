#ifndef __COMMAND_H__
#define __COMMAND_H__

// ----------------------------------------------------------------------------
// includes (primero los <> despues los "")
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// defines
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

/**
 * Documentar.
*/
class Command {
    private:

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Command();

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Command(const Command&) = delete;
        Command& operator=(const Command&) = delete;

        /** 
         * Habilitamos el constructor por movimiento y su operador.
        */
        Command(Command&& other);
        Command& operator=(Command&& other);

        /** 
         * Descripcion: destructor.
        */
        ~Command();
};

// ----------------------------------------------------------------------------
#endif // __COMMAND_H__
