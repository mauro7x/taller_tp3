#ifndef __HELP_H__
#define __HELP_H__

// ----------------------------------------------------------------------------
#include "Command.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Help : public Command {
    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Help();

        /**
         * Descripcion: ejecucion del comando Help.
         * Parametros: -
         * Retorno: mensaje respuesta.
        */
        std::string operator()(unsigned short secret_number) const override;
};

// ----------------------------------------------------------------------------
#endif // __HELP_H__
