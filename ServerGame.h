#ifndef __SERVER_GAME_H__
#define __SERVER_GAME_H__

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Command.h"
#include "Exception.h"
#include "Results.h"
#include "ServerProtocol.h"
#include "Thread.h"
#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class ServerGame : public Thread {
   private:
    ServerProtocol protocol;
    ProtectedResults& results;
    uint16_t secret_number;
    unsigned int remaining_attempts;
    bool is_running;

   public:
    /**
     * Descripcion: constructor. Inicia el protocolo pasandole el fd
     * recibido, se supone correctamente inicializado por el Accepter.
     *
     * Parametros: fd del socket peer, numero secreto, intentos restantes.
     */
    ServerGame(int fd, ProtectedResults& results, uint16_t secret_number);

    /**
     * Deshabilitamos el constructor por copia y su operador.
     */
    ServerGame(const ServerGame&) = delete;
    ServerGame& operator=(const ServerGame&) = delete;

    /**
     * Deshabilitamos el constructor por movimiento y su operador.
     */
    ServerGame(ServerGame&& other) = delete;
    ServerGame& operator=(ServerGame&& other) = delete;

    /**
     * Descripcion: hilo de ejecucion del juego con un cliente.
     *
     * Parametros: -
     *
     * Retorno: -
     */
    void run() override;

    /**
     * Descripcion: verifica si el hilo termino de ejecutarse.
     *
     * Parametros: -
     *
     * Retorno: TRUE si el hilo ya termino, FALSE si se esta ejecutando.
     */
    bool isOver();

    /**
     * Descripcion: se termina la ejecución de forma forzosa.
     *
     * Parametros: -
     *
     * Retorno: -
     */
    void stop();

    /**
     * Descripcion: destructor.
     */
    ~ServerGame();
};

// ----------------------------------------------------------------------------
#endif  // __SERVER_GAME_H__
