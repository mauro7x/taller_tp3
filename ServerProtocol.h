#ifndef __SERVER_PROTOCOL_H__
#define __SERVER_PROTOCOL_H__

// ----------------------------------------------------------------------------
#include <string>
#include <arpa/inet.h>

#include "Socket.h"
#include "Command.h"
#include "Guess.h"
#include "Surrender.h"
#include "Help.h"

#include "SocketClosedException.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ServerProtocol {
    private:
        Socket peer;

    public:
        /**
         * Descripcion: constructor para los ClientHandlers del servidor.
         * 
         * Parametros: file descriptor del socket peer valido.
        */
        ServerProtocol(const int fd);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        ServerProtocol(const ServerProtocol&) = delete;
        ServerProtocol& operator=(const ServerProtocol&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        ServerProtocol(ServerProtocol&& other) = delete;
        ServerProtocol& operator=(ServerProtocol&& other) = delete;

        /** 
         * Descripcion: sobrecarga del operador >> para recibir un comando.
         * Recibe primero un char que indica el tipo, y si se trata de un Guess
         * recibe un uint16_t.
         * Aloca la memoria necesaria para el comando recibido en el puntero
         * recibido por parametro.
         * En caso de que se cierre el socket, se lanza la excepcion
         * ClosedSocketException.
         * 
         * Parametros: puntero al comando a recibir.
         * 
         * Retorno: -
         * 
         * SE DEBE LIBERAR LA MEMORIA APUNTADA POR EL PUNTERO RETORNADO
        */
        void operator>>(Command* &cmd) const;

        /** 
         * Descripcion: sobrecarga del operador << para enviar un mensaje.
         * Envia primero la longitud del mismo como un uint16_t, y luego
         * el mensaje.
         * 
         * Parametros: string a enviar pasado por referencia.
         * 
         * Retorno: -
        */
        void operator<<(const std::string& msg) const;

        /**
         * Descripcion: cierra forzosamente la conexión.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void stop();
        
        /** 
         * Descripcion: destructor. Apaga el peer socket haciendole shutdown.
        */ 
        ~ServerProtocol();
};

// ----------------------------------------------------------------------------
#endif // __SERVER_PROTOCOL_H__
