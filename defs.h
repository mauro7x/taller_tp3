#ifndef __DEFS_H__
#define __DEFS_H__

// ----------------------------------------------------------------------------
/**
 * Se incluyen en este header todos los defines de propósito general
 * para el trabajo práctico.
*/
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Codigos de retorno
#define ERROR 1
#define USAGE_ERROR 1

// Mensajes de error
#define USAGE_ERROR_MSG "Error: argumentos invalidos."

// Mensajes del servidor
#define WIN_MSG "Ganaste"
#define LOSS_MSG "Perdiste"
#define HELP_MSG "Comandos válidos:​\n​" \
                  "\tAYUDA: despliega la lista de comandos válidos​\n"\
                  "\t​RENDIRSE: pierde el juego automáticamente​\n"\
                  "\tXXX: Número de 3 cifras a ser enviado al servidor"\
                  "para adivinar el número secreto"

// Tipos de comandos
#define HELP 'h'
#define SURRENDER 's'
#define GUESS 'n'

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#endif // __DEFS_H__
