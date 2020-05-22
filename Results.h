#ifndef __RESULTS_H__
#define __RESULTS_H__

// ----------------------------------------------------------------------------
#include <mutex>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
/**
 * Recurso compartido: Results.
 * 
 * Al ser un objeto compartido entre hilos, utiliza MUTEX como mecanismo de
 * sincronización de acceso. Todos los métodos que se ofrecen en su API
 * están protegidos y pueden ser utilizados con la garantía de que no se
 * generaran condition-races.
*/
class Results {
    private:
        unsigned int n_wins, n_losses;
        std::mutex m;

    public:
        /** 
         * Descripcion: constructor. Inicia wins y losses en 0.
         * 
         * Parametros: -
        */
        Results();

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        Results(const Results&) = delete;
        Results& operator=(const Results&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        Results(Results&& other) = delete;
        Results& operator=(Results&& other) = delete;

        /** 
         * Descripcion: agrega una victoria.
         
         * Parametros: -
         * 
         * Retorno: -
        */
        void addWin();

        /** 
         * Descripcion: agrega una victoria.
         
         * Parametros: -
         * 
         * Retorno: -
        */
        void addLoss();

        /** 
         * Descripcion: retorna el valor de victorias.
         
         * Parametros: -
         * 
         * Retorno: unsigned int con las victorias.
        */
        unsigned int wins();
        
        /** 
         * Descripcion: retorna el valor de derrotas.
         
         * Parametros: -
         * 
         * Retorno: unsigned int con las derrotas.
        */
        unsigned int losses();

        /** 
         * Descripcion: destructor.
        */
        ~Results();
};

// ----------------------------------------------------------------------------
#endif // __RESULTS_H__
