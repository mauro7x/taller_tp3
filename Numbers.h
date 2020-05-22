#ifndef __NUMBERS_H__
#define __NUMBERS_H__

// ----------------------------------------------------------------------------
#include <cstdint>
#include <fstream>
#include <iterator>
#include <list>
#include <string>

#include "InputErrorException.h"
#include "defs.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

class Numbers {
   private:
    std::list<uint16_t> numbers;
    std::list<uint16_t>::iterator it;

    /**
     * Descripcion: chequea que sea un numero valido.
     *
     * Parametros: numero a chequear.
     *
     * Retorno: -
     *
     * Si el numero no está en el rango permitido o tiene
     * cifras repetidas, lanza excepcion InputErrorException.
     *
     * >THROW EXPLICITO DE EXCEPTION.
     */
    void _checkIfValid(const uint64_t& input_number) const;

    /**
     * Descripcion: parsea los numeros en el archivo, chequeando
     * que su formato sea correcto, y los agrega a la lista.
     *
     * Parametros: archivo abierto.
     *
     * Retorno: -
     *
     * Si algun numero no cumple con el formato pedido, se lanza
     * una excepción.
     *
     * >THROW EXPLICITO DE EXCEPTION.
     */
    void _parseNumbers(std::ifstream& file);

   public:
    /**
     * Descripcion: constructor. Abre el archivo y arma la lista de
     * numeros.
     *
     * Parametros: ruta al archivo pasada por referencia.
     *
     * >THROW EXPLICITO DE EXCEPTION.
     */
    explicit Numbers(const std::string& filepath);

    /**
     * Deshabilitamos el constructor por copia y su operador.
     */
    Numbers(const Numbers&) = delete;
    Numbers& operator=(const Numbers&) = delete;

    /**
     * Deshabilitamos el constructor por movimiento y su operador.
     */
    Numbers(Numbers&& other) = delete;
    Numbers& operator=(Numbers&& other) = delete;

    /**
     * Descripcion: devuelve el proximo numero a utilizar, obtenido
     * de forma round robin.
     *
     * Parametros: -
     *
     * Retorno: numero secreto a utilizar, uint16_t
     */
    uint16_t operator()();

    /**
     * Descripcion: destructor.
     */
    ~Numbers();
};

// ----------------------------------------------------------------------------
#endif  // __NUMBERS_H__
