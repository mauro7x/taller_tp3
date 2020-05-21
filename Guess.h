#ifndef __GUESS_H__
#define __GUESS_H__

// ----------------------------------------------------------------------------
#include "Command.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Guess : public Command {
    private:
        unsigned short int value;

    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Guess(unsigned short int value);

        /**
         * Descripcion: retorna el valor numerico del intento.
         * Parametros: -
         * Retorno: valor numerico de 2 bytes.
        */
        unsigned short int number() const;

        /**
         * Descripcion: ejecucion del comando Guess.
         * Parametros: -
         * Retorno: mensaje respuesta.
        */
        std::string operator()(unsigned short secret_number) const override;
};

// ----------------------------------------------------------------------------
#endif // __GUESS_H__
