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
#define UNKNOWN_COMMAND_ERROR_MSG "Error: comando inválido. "\
                                  "Escriba AYUDA para obtener ayuda"
#define INVALID_NUMBER_ERROR_MSG "Número inválido. "\
                                 "Debe ser de 3 cifras no repetidas"

// Mensajes del servidor fijos
#define WIN_MSG "Ganaste"
#define LOSS_MSG "Perdiste"
#define HELP_MSG "Comandos válidos:​\n​" \
                  "\tAYUDA: despliega la lista de comandos válidos​\n"\
                  "\t​RENDIRSE: pierde el juego automáticamente​\n"\
                  "\tXXX: Número de 3 cifras a ser enviado al servidor "\
                  "para adivinar el número secreto"

// Rangos de numeros permitidos
#define MIN_ALLOWED_NUMBER 100
#define MAX_ALLOWED_NUMBER 999

// Rangos de representacion de unsigned short int
#define MIN_POSSIBLE_NUMBER 0
#define MAX_POSSIBLE_NUMBER 65535
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#endif // __DEFS_H__
