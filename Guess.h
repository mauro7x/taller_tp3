#ifndef __GUESS_H__
#define __GUESS_H__

// ----------------------------------------------------------------------------
#include "Command.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Guess : public Command {
    private:
        unsigned short int value;

        /**
         * Description: chequea si el valor numérico es valido.
         * 
         * Parametros: -
         * 
         * Retorno: TRUE si el valor es valido, FALSE si no.
        */
        bool _isValid() const;

        /**
         * Description: cuenta la cantidad de digitos correctos.
         * 
         * Parametros: numero correcto para comparar.
         * 
         * Retorno: cantidad de digitos correctos, >= 0.
        */
        size_t _countCorrectDigits(unsigned short int secret_number) const;

        /**
         * Description: cuenta la cantidad de digitos regulares, es decir,
         * aquellos que estén en el numero pero en otra posición.
         * 
         * Parametros: numero correcto para comparar.
         * 
         * Retorno: cantidad de digitos regulares, >= 0.
        */
        size_t _countRegularDigits(unsigned short int secret_number) const;

        /**
         * Description: formatea la respuesta segun el enunciado.
         * 
         * Parametros: respuesta a formatear pasada por referencia, cantidad
         * de digitos correctos y cantidad de digitos regulares.
         * 
         * Retorno: -
        */
        void _formatReply(std::string& reply, size_t correct_digits,
                          size_t regular_digits) const;

    public:
        /** 
         * Descripcion: constructor.
         * 
         * Parametros: valor numerico de 2 bytes del intento.
        */
        Guess(unsigned short int value);

        /**
         * Descripcion: retorna el valor numerico del intento.
         * 
         * Parametros: -
         * 
         * Retorno: valor numerico de 2 bytes.
        */
        unsigned short int number() const;

        /**
         * Descripcion: se ejecuta el intento de adivinar el numero secreto
         * de acuerdo a las reglas establecidas por el enunciado.
         * 
         * Parametros: numero secreto a adivinar, respuesta a llenar pasada
         * por referencia, intentos restantes pasados por referencia.
         * 
         * Retorno: CONTINUE == continuar.
         *          WIN == el cliente gano.
         *          LOSS == el cliente perdió.
        */
        state operator()(unsigned short int secret_number, std::string& reply,
                         unsigned int& remaining_attempts) const override;
};

// ----------------------------------------------------------------------------
#endif // __GUESS_H__
