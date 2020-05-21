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
         * 
         * Parametros: -
        */
        Surrender();

        /**
         * Descripcion: se escribe el mensaje LOSS_MSG en reply, y se retorna
         * el state LOSS.
         * 
         * Parametros: numero secreto a adivinar, respuesta a llenar pasada
         * por referencia, intentos restantes pasados por referencia.
         * 
         * Retorno: state LOSS.
        */
        state operator()(unsigned short int secret_number, std::string& reply,
                         unsigned int& remaining_attempts) const override;
};

// ----------------------------------------------------------------------------
#endif // __SURRENDER_H__
