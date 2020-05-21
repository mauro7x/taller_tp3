#ifndef __CLIENT_PROTOCOL_H__
#define __CLIENT_PROTOCOL_H__

// ----------------------------------------------------------------------------
#include <string>
#include <arpa/inet.h>

#include "Socket.h"
#include "Command.h"
#include "Guess.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ClientProtocol {
    private:
        Socket socket;

        /**
         * Descripcion: realiza la serialización correspondiente desde
         * un puntero a comando a un string serializado listo para enviar.
         * 
         * Parametros: puntero a comando.
         * 
         * Retorno: comando serializado en string.
        */
        std::string _serialize(Command* cmd) const;

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
         * 
         * Parametros: string a recibir pasado por referencia
         * 
         * Retorno: -
        */
        void operator>>(std::string& msg) const;


        /** 
         * Descripcion: destructor.
        */ 
        ~ClientProtocol();
};

// ----------------------------------------------------------------------------
#endif // __CLIENT_PROTOCOL_H__
