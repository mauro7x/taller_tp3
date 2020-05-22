#ifndef __RESULTS_H__
#define __RESULTS_H__

// ----------------------------------------------------------------------------
#include <mutex>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
/**
 * Recurso compartido: ProtectedResults.
 * 
 * Al ser un objeto compartido entre hilos, utiliza MUTEX como mecanismo de
 * sincronización de acceso. Todos los métodos que se ofrecen en su API
 * están protegidos y pueden ser utilizados con la garantía de que no se
 * generaran condition-races.
*/
class ProtectedResults {
    private:
        unsigned int n_wins, n_losses;
        std::mutex m;

    public:
        /** 
         * Descripcion: constructor. Inicia wins y losses en 0.
         * 
         * Parametros: -
        */
        ProtectedResults();

        /** 
         * Deshabilitamos el constructor por copia y su operador.
        */
        ProtectedResults(const ProtectedResults&) = delete;
        ProtectedResults& operator=(const ProtectedResults&) = delete;

        /** 
         * Deshabilitamos el constructor por movimiento y su operador.
        */
        ProtectedResults(ProtectedResults&& other) = delete;
        ProtectedResults& operator=(ProtectedResults&& other) = delete;

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
        ~ProtectedResults();
};

// ----------------------------------------------------------------------------
#endif // __RESULTS_H__
