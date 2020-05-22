#ifndef __DEFS_H__
#define __DEFS_H__

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// MENSAJES

// Mensajes de error
#define USAGE_ERROR_MSG "Error: argumentos invalidos."
#define UNKNOWN_COMMAND_ERROR_MSG "Error: comando inválido. "\
                                  "Escriba AYUDA para obtener ayuda"
#define INVALID_NUMBER_ERROR_MSG "Número inválido. "\
                                 "Debe ser de 3 cifras no repetidas"
#define INVALID_FORMAT_INPUT_MSG "Error: formato de los números inválidos"
#define OUT_OF_RANGE_INPUT_MSG "Error: archivo con números fuera de rango"

// Mensajes del servidor
#define WIN_MSG "Ganaste"
#define LOSS_MSG "Perdiste"
#define HELP_MSG "Comandos válidos:​\n​" \
                  "\tAYUDA: despliega la lista de comandos válidos​\n"\
                  "\t​RENDIRSE: pierde el juego automáticamente​\n"\
                  "\tXXX: Número de 3 cifras a ser enviado al servidor "\
                  "para adivinar el número secreto"
#define N_CORRECT_MSG(correct) std::to_string(correct) + " bien"
#define N_REGULAR_MSG(regular) std::to_string(regular) + " regular"
#define N_CORRECT_N_REGULAR_MSG(correct, regular) std::to_string(correct) +\
                                                  " bien, " +\
                                                  std::to_string(regular) +\
                                                  " regular"
#define ALL_INCORRECT_MSG "3 mal"

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// CONFIGURACION

// Rango de numeros permitidos
#define MIN_ALLOWED_NUMBER 100
#define MAX_ALLOWED_NUMBER 999

// Intentos permitidos
#define ATTEMPTS 10
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// OTROS

// Rangos de representacion de uint16_t
#define MIN_POSSIBLE_NUMBER 0
#define MAX_POSSIBLE_NUMBER 65535
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#endif // __DEFS_H__
