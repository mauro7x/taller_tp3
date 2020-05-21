#ifndef __SURRENDER_H__
#define __SURRENDER_H__

// ----------------------------------------------------------------------------
#include "Command.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Surrender : public Command {
    public:
        /** 
         * Descripcion: constructor.
         * Parametros: -
        */
        Surrender();

        /**
         * Descripcion: ejecucion del comando Surrender.
         * Parametros: -
         * Retorno: mensaje respuesta.
        */
        std::string operator()(unsigned short secret_number) const override;
};

// ----------------------------------------------------------------------------
#endif // __SURRENDER_H__
