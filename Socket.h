#ifndef __SOCKET_H__
#define __SOCKET_H__

//-----------------------------------------------------------------------------
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstdint>

#include "Exception.h"
#include "SocketClosedException.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

/**
 * Socket. Descripcion. FALTA DOCUMENTAR.
*/
class Socket {
    private:
        int fd;
        bool fd_valid;

        /** (SERVER-SIDE)
         * Descripcion: obtiene la dirección donde se abrira el servidor a la
         * escucha de conexiones remotas.
         * 
         * Parametros: puerto, estructura de direccion.
         * 
         * Retorno: -
         * 
         * Se debe liberar la memoria reservada apuntada por address.
         * >THROW EXPLICITO DE EXCEPTION (no es necesario liberar address).
        */
        void _setServerAddress(const std::string& port, addrinfo** address)
                               const;

        /** (CLIENT-SIDE)
         * Descripcion: obtiene las direcciones a las que se tratará de
         * conectar el servidor.
         * 
         * Parametros: hostname, puerto, estructura de direcciones.
         * 
         * Retorno: -
         * 
         * Se debe liberar la memoria reservada apuntada por addresses.
         * >THROW EXPLICITO DE EXCEPTION (no es necesario liberar addresses).
        */
        void _setClientAddresses(const std::string& hostname,
                                 const std::string& port,
                                 addrinfo** addresses) const;

        /** 
         * Descripcion: llama a la syscall socket() para obtener el fd.
         * 
         * Parametros: estructura de direccion para crear el socket,
         * estructura de direcciones a liberar en caso de error.
         * 
         * Retorno: -
         * 
         * En caso de error libera la memoria de all_addresses.
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void _setFd(addrinfo* address, addrinfo* all_addresses);
        
        /** (SERVER-SIDE)
         * Descripcion: arregla el problema de TIMEWAIT de existir.
         * 
         * Parametros: estructura de dirección.
         * 
         * Retorno: -
         * 
         * En caso de error libera la memoria de address.
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void _fixTimeWait(addrinfo* address) const;

        /** (SERVER-SIDE)
         * Descripcion: realiza el bind del socket a address.
         * 
         * Parametros: estructura de dirección a la que bindear el socket.
         * 
         * Retorno: -
         * 
         * Libera la memoria de address.
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void _bind(addrinfo* address) const;

        /** (SERVER-SIDE)
         * Descripcion: pone a la escucha al servidor. Se establece
         * @max_queued_clients como limite a la cantidad de clientes encolados
         * esperando ser aceptados.
         * 
         * Parametros: cantidad límite de clientes encolados.
         * 
         * Retorno: -
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void _listen(const int max_queued_clients) const;

        /** (CLIENT-SIDE)
         * Descripcion: intenta conectarse a todas las direcciones en la 
         * estructura de direcciones recibida. Si no lo logra, lanza excepción.
         * 
         * Parametros: estructura de direcciones.
         * 
         * Retorno: -
         * 
         * Libera la memoria de addresses.
         * >THROW EXPLICITO DE EXCEPTION.
        */
        void _tryToConnectTo(addrinfo* addresses);

        /** 
         * Descripcion: si el fd es valido, lo cierra.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void _closeFdIfValid();

    public:
        /** (SERVER-SIDE)
         * Diseñado para ser utilizado por el SERVIDOR para ponerse a la
         * escucha de conexiones entrantes.
         * 
         * Descripcion: constructor con un puerto y la cantidad de clientes
         * que pueden haber simultaneamente esperando a ser aceptados.
         * 
         * Parametros: puerto , máxima cantidad de clientes encolados.
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        Socket(const std::string& port, const int max_queued_clients);

        /** (SERVER-SIDE)
         * Diseñado para ser utilizado por el SERVIDOR para crear los
         * socket peer con los que se comunica con sus clientes.
         * 
         * Descripcion: constructor con fd.
         * 
         * Parametros: file descriptor valido correctamente inicializado.
         * 
         * Se toma la responsabilidad del cierre del fd.
        */
        explicit Socket(const int fd);

        /** (CLIENT-SIDE)
         * Diseñado para ser utilizado por el CLIENTE para conectarse
         * a un determinado servidor.
         * 
         * Descripcion: constructor con hostname y puerto.
         * 
         * Parametros: nombre del host y puerto al que conectarse.
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        Socket(const std::string& hostname, const std::string& port);

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;

        /** 
         * Habilitamos el constructor por movimiento y su operador.
        */
        Socket(Socket&& other);
        Socket& operator=(Socket&& other);

        /** (SERVER-SIDE)
         * Descripcion: acepta la conexión de un cliente.
         * 
         * Parametros: -
         * 
         * Retorno: file descriptor del socket aceptado.
         * 
         * No toma la responsabilidad de cerrar el fd devuelto.
         * >THROW EXPLICITO DE EXCEPTION.
        */
        int accept() const;

        /** 
         * Descripcion: envia len bytes de source a través del socket.
         * 
         * Parametros: source const char*, cantidad de bytes.
         * 
         * Retorno: N, si n>0: cantidad de bytes enviados.
         *             si n==0: el socket fue cerrado.
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        ssize_t send(const char* source, const ssize_t len) const;

        /** 
         * Descripcion: recibe len bytes del socket en el buffer.
         * 
         * Parametros: buffer donde almacenar los len bytes recibidos. 
         * 
         * Retorno: N, si n>0: cantidad de bytes recibidos.
         *             si n==0: el socket fue cerrado.
         * 
         * >THROW EXPLICITO DE EXCEPTION.
        */
        ssize_t recv(char* buffer, const ssize_t len) const;

        //---------------------------------------------------------------------
        // Sobrecarga de operadores >> << para envio y recepción de distintos
        // tipos de datos específicos. Aplica la misma documentación para
        // >> que para recv, y para << que para send.

        ssize_t operator<<(uint16_t n) const;
        ssize_t operator>>(uint16_t& n) const;

        ssize_t operator<<(const std::string& msg) const;

        ssize_t operator<<(char c) const;
        ssize_t operator>>(char& c) const;

        //---------------------------------------------------------------------

        /** 
         * Descripcion: desconecta uno o ambos canales del socket.
         * 
         * Parametros: canal/es a desconectar, si no se recibe, por defecto se
         * desconectan ambos canales (lectura y escritura).
         * 
         * Retorno: -
        */
        void shutdown(const int& channel=SHUT_RDWR) const;

        /** 
         * Descripcion: cierra el socket si el mismo es válido.
         * 
         * Parametros: -
         * 
         * Retorno: -
        */
        void close();

        /** 
         * Descripcion: destructor.
         * 
         * Cierra el file descriptor asociado al socket.
        */
        ~Socket();
};

//-----------------------------------------------------------------------------
#endif // __SOCKET_H__
