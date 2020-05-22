#ifndef __CLIENT_PROTOCOL_H__
#define __CLIENT_PROTOCOL_H__

// ----------------------------------------------------------------------------
#include <string>
#include <arpa/inet.h>

#include "Socket.h"
#include "Command.h"
#include "Guess.h"

#include "ClosedSocketException.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ClientProtocol {
    private:
        Socket socket;

    public:
        /**
         * Descripcion: constructor. Crea el Socket cliente, conectandolo
         * al hostname y puertos previstos.
         * 
         * Parametros: hostname y puerto al que conectarse.
        */
        ClientProtocol(const std::string& hostname, const std::string& port);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        ClientProtocol(const ClientProtocol&) = delete;
        ClientProtocol& operator=(const ClientProtocol&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        ClientProtocol(ClientProtocol&& other) = delete;
        ClientProtocol& operator=(ClientProtocol&& other) = delete;

        /** 
         * Descripcion: sobrecarga del operador << para enviar un comando.
         * Envia el comando segun el protocolo, enviando primero el tipo como
         * un char, y en caso de ser un Guess, envia el uint16_t.
         * 
         * Parametros: puntero al comando a enviar.
         * 
         * Retorno: -
         * 
         * LIBERA LA MEMORIA APUNTADA POR EL PUNTERO RECIBIDO.
        */
        void operator<<(Command* cmd) const;

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un mensaje.
         * Recibe primero la longitud del mismo en un uint16_t, y luego
         * el mensaje en sí.
         * En caso de que se cierre el socket, se lanza la excepcion
         * ClosedSocketException.
         * 
         * Parametros: string a recibir pasado por referencia
         * 
         * Retorno: -
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void operator>>(std::string& msg) const;

        /** 
         * Descripcion: destructor.
        */ 
        ~ClientProtocol();
};

// ----------------------------------------------------------------------------
#endif // __CLIENT_PROTOCOL_H__
