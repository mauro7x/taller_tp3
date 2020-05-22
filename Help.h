#ifndef __HELP_H__
#define __HELP_H__

// ----------------------------------------------------------------------------
#include <string>

#include "Command.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Help : public Command {
   public:
    /**
     * Descripcion: constructor.
     *
     * Parametros: -
     */
    Help();

    /**
     * Descripcion: se escribe el mensaje HELP_MSG en reply, y se retorna
     * el state CONTINUE.
     *
     * Parametros: numero secreto a adivinar, respuesta a llenar pasada
     * por referencia, intentos restantes pasados por referencia.
     *
     * Retorno: state CONTINUE.
     */
    state operator()(uint16_t secret_number, std::string& reply,
                     unsigned int& remaining_attempts) const override;
};

// ----------------------------------------------------------------------------
#endif  // __HELP_H__
