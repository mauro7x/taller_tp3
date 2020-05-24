# Informe TP3

## Detalles administrativos

* **Materia:** Taller de Programación I
* **Año y cuatrimestre:** 1°C 2020
* **Alumno:** PARAFATI, Mauro
* **Padrón:** 102749
* [**Link al repositorio**](https://github.com/mauro7x/taller_tp3)

<!-- ##################################################################### -->

# Tabla de contenidos

1. [Presentación del trabajo](#presentacion)
    * [Introducción](#introduccion)
    * [Descripción](#descripcion)
2. [Especificaciones provistas](#especificaciones)
    * [Formato de invocación de los comandos](#comandos)
        * [Servidor](#server_cmd)
        * [Cliente](#client_cmd)
    * [Entrada y salida estándar](#stdio)
        * [Servidor](#server_stdio)
        * [Cliente](#client_stdio)
    * [Códigos de retorno](#retornoespecifico)
    * [Protocolo](#protocolo)
    * [Comandos](#comandos)
        * [AYUDA](#h)
        * [RENDIRSE](#s)
        * [<NÚMERO DE 3 CIFRAS>](#n)
        * [COMANDO INVÁLIDO](#invalid)
    * [Restricciones](#restricciones)
3. [Introducción teórica](#teorica)
4. [Resolución](#resolucion)
5. [Códigos de retorno](#retorno)
6. [Conclusiones](#conclusiones)

<!-- ##################################################################### -->

---

# 1. Presentación del trabajo <a name="presentacion"></a>

## Introducción <a name="introduccion"></a>

> Se desarrollará un aplicativo por consola, con cliente y servidor, para poder jugar al juego de "Adivina el número". El servidor deberá ser capaz de aceptar y atender múltiples clientes en simultáneo.

## Descripción <a name="descripcion"></a>

> El juego consiste en que una persona (S) **debe pensar un número de 3 cifras no repetidas** (N), entre 100 y 999, y otra persona (C) debe **adivinar el número en menos de 10 intentos**.
>
> Para esto, por cada número que C intenta adivinar, S le contesta de la siguiente forma:
>
> - Si alguna de las cifras que dijo C se encuentra en el número N, pero está en otra posición, se le computará como **1 regular**.
> - Si alguna de las cifras del número que propone C concuerda en valor y posición al número N, se le computará como **1 bien**.
> - Si ninguna de las cifras del número que propone C se encuentra en el número N, se le computará como **3 mal**.
>
> El juego termina cuando **C adivine el número**, habiendo este ganado, o cuando hayan pasado **10 intentos**, computándose como **derrota** la partida.

---

# 2. Especificaciones provistas <a name="especificaciones"></a>

## Formato de invocación de los comandos <a name="comandos"></a>

### Servidor <a name="server_cmd"></a>

> Para ejecutar el **servidor**, se utiliza:
> ```
> ./server <puerto/servicio> <números>
> ```
> Donde `<puerto/servicio>` es el puerto TCP (o servicio) el cual el servidor deberá **escuchar** las **conexiones entrantes**.
> 
> El parámetro `<números>` representa la ruta a un archivo con una lista de números que el servidor recorrerá en forma **round robin** y usará para que sea el número a adivinar por el cliente en cada partida. El servidor deberá **leerlo al inicio** y obtener la información relevante. Esta lista se encuentra representada por distintos números separados por un caracter nueva línea (`\n`).

#### Ejemplo de archivo

> Un ejemplo de archivo puede ser el siguiente:
> ```
> 748
> 928
> 903
> ```
> 
> Cuando el primer cliente se conecte, el servidor usará el número 748 para que el cliente lo adivine. Luego usará el número 928 cuando se conecte alguien nuevo, y así sucesivamente, recorriendo en anillo los valores (el siguiente conectado deberá adivinar el número 903, y cuando haya un cuarto cliente conectado, se repetirá el número 748).

### Cliente <a name="client_cmd"></a>

> Para ejecutar el **cliente**, se utiliza:
> ```
> ./client <ip/hostname> <port/service>
> ```
> El cliente se conectará al servidor corriendo en la máquina con dirección IP `<ip>` (o `<hostname>`), en el puerto (o servicio) TCP `<puerto/servicio>`. Luego se quedará **escuchando** por **entrada estándar** los **comandos** a enviarle al servidor.

## Entrada y salida estándar <a name="stdio"></a>

### Servidor <a name="server_stdio"></a>

#### Entrada estándar

> El servidor esperará el caracter `q` por entrada estándar. Cuando lo reciba, el servidor deberá **cerrar el socket aceptador**, y **esperar a que las conexiones se cierren** antes de liberar los recursos y retornar.

#### Salida estándar

> Al finalizar la ejecución, el servidor deberá **imprimir una estadística de las partidas jugadas**, contando la cantidad de victorias y derrotas que tuvo durante su ejecución. El formato será:
> ```
> Estadísticas:\n\tGanadores:  <cantidad de ganadores>\n\tPerdedores: <cantidad de perdedores>\n
> ```
> Notar que las 3 líneas se encuentran terminadas con una nueva línea (`\n`), las líneas de ganadores y perdedores tienen una tabulación al inicio, y la de ganadores tiene dos espacios después de los dos puntos,mientras que la de perdedores tiene un espacio.

#### Salida de error estándar

> El servidor imprimirá por la salida de error cuando uno de los siguientes **errores** ocurren:
>
> - Si la cantidad de parámetros es **inválida**, se imprimirá:
>   ```
>   Error: argumentos invalidos.
>   ```
>
> - Si alguno de los números de la lista que recibe por parámetro **no se encuentra entre los valores 100 y 999**, el servidor imprimirá:
>   ```
>   Error: archivo con números fuera de rango
>   ```
>
> - Si alguno de los números de la lista posee **cifras repetidas**, se imprimirá:
>   ```
>   Error: formato de los números inválidos
>   ```

### Cliente <a name="client_stdio"></a>

#### Entrada estándar

> Por entrada estándar, el cliente recibirá los **comandos** que deberá enviar al servidor. Estos son:
>
> - `AYUDA`
> - `RENDIRSE`
> - `<un número de 3 cifras>`
>
> Los detalles de los comandos serán detallados en la sección del [**protocolo**](#protocolo).

#### Salida estándar

> Por salida estándar se imprimirán los **mensajes que se reciben del servidor** de acuerdo a los comandos enviados. Estos se verán en la sección del [**protocolo**](#protocolo).
> 
> El cliente también imprimirá por **salida estándar algunos mensajes de error**, entre ellos, imprimirá:
>
> - Cuando la cantidad de parámetros de comando de líneas **no es el correcto**, se imprimirá:
>   ```
>   Error: argumentos invalidos.
>   ```
>
> - Si el **comando recibido no es válido**, el cliente imprimirá:
>   ```
>   Error: comando inválido. Escriba AYUDA para obtener ayuda
>   ```

## Códigos de retorno <a name="retornoespecifico"></a>

> El servidor devolverá **0 si su ejecución fue exitosa**, o **1 en caso contrario**.
> 
> El cliente deberá **devolver siempre 0**, imprimiendo por **salida estándar los mensajes de errores** que se detallan en la sección siguiente.

## Protocolo <a name="protocolo"></a>

> El protocolo se compone de las siguientes reglas:
>
> - Todos los comandos se enviarán como 1 byte, con el caracter ascii del comando (`h` para ayuda, `s` para rendirse y `n` para enviar un número).
>   - En el caso de que se envíe un número, seguido del comando se enviará un **entero sin signo de 2 bytes** en formato `big-endian` que representa el número recibido por entrada estándar.
>
> - Los **strings** deberán ser enviados primero con un **entero sin signo de 4 bytes**, en formato `big-endian`, indicando el **largo del string**, y luego se envían la tira de bytes del string, sin tener en cuenta el caracter de terminación `\0`.

## Comandos <a name="comandos"></a>

### AYUDA <a name="h"></a>

> Cuando el cliente reciba por entrada estándar el string `AYUDA`, le enviará el comando `h` al servidor como se dijo anteriormente. El servidor le responderá con un mensaje de ayuda, enviado como un string único, con el siguiente mensaje:
> ```
> Comandos válidos:\n\tAYUDA: despliega la lista de comandos válidos \n\tRENDIRSE: pierde el juego automáticamente\n\tXXX: Número de 3 cifras a ser enviado al servidor para adivinar el número secreto
> ```
> Este comando **no** gasta un intento para adivinar el número.

### RENDIRSE <a name="s"></a>

> El cliente enviará el byte de valor `s` (ascii 115, 0x73 en hexa). El servidor le responderá con el string:
> ```
> Perdiste
> ```

### <NÚMERO DE CIFRAS> <a name="n"></a>

> Cuando el cliente reciba un número por la entrada estándar, deberá enviar primero un byte con el valor `n` (110 en valor ascii, 0x6E en hexa), y luego enviará el número, en el formato previamente indicado (2 bytes sin signo en big endian).
>
> El servidor **procesará el número y le contestará al cliente** de la siguiente forma:
> 
> - Si tuvo uno o más números regulares, le enviará el string:
>   ```
>   n regular
>   ```
>   Con n la cantidad de números regulares que tuvo en ese intento.
>
> - Si tuvo uno o dos números bien, le enviará:
>   ```
>   n bien
>   ```
>
> - Si tuvo una combinación de ambas (por ejemplo, 1 bien y 2 regulares), siempre se imprimirá primero los bien, y luego los regulares, separado por coma:
>   ```
>   1 bien, 2 regular
>   ```
>
> - Si las tres cifras no se encuentran en el número secreto:
>   ```
>   3 mal
>   ```
>
> - Si el número que ingresó el cliente es exactamente el número secreto, este le contestará:
>   ```
>   Ganaste
>   ```
>   E incrementará en 1 la cantidad de ganadores que hubo durante la ejecución. El cliente se irá de forma ordenada.
>
> - Si pasaron los 10 intentos y el cliente no adivinó el número:
>   ```
>   Perdiste
>   ```
>   Y el servidor incrementará en 1 la cantidad de derrotas.
>
> El servidor también hará **chequeos de error cuando recibe un número**. En particular, enviará:
>
> - Si el número recibido es menor a 100, o mayor a 999, o si alguna de las cifras se repiten (por ejemplo, se pasa el número 990) se enviará:
> ```
> Número inválido. Debe ser de 3 cifras no repetidas
> ```

### COMANDO INVÁLIDO <a name="invalid"></a>

> Finalmente, si el cliente recibe por entrada estándar un **comando inválido**, se imprimirá el mensaje:
> ```
> Error: comando inválido. Escriba AYUDA para obtener ayuda
> ```

## Restricciones <a name="restricciones"></a>

> La siguiente es una **lista de restricciones técnicas** exigidas por el cliente:
> 1. El sistema debe desarrollarse en ISO C++11.
> 2. Está prohibido el uso de variables globales.
> 3. Se deberá aplicar al menos 1 polimorfismo
> 4. Se deberá sobrecargar el operador `operator()` en alguna clase.

---

# 3. Introducción teórica <a name="teorica"></a>

En los últimos dos trabajos prácticos realizados, el **TP1** que trató principalmente sobre la construcción de un sistema **Cliente/Servidor** y el **TP2** que trató sobre la implementación de un sistema **multi-hilo**, realicé una breve introducción teórica a ambos temas, pues fueron conceptos nuevos para mi y me pareció útil adjuntar la información que recolecté para trabajar en estos ejercicios.

Este trabajo práctico número 3, **combina ambos aspectos**: la idea es hacer un juego **cliente/servidor** y que se ejecute concurrentemente utilizando **distintos hilos de ejecución**. Es decir: los contenidos teóricos son los mismos, y las herramientas a utilizar son las mismas: *sockets, protocolos, threads, condition variables, mutex, etc.*

Para no sobrecargar el informe de contenido que ya describí en informes anteriores, prefiero **utilizar las herramientas directamente**, y adjuntar en este mismo trabajo práctico ambos informes anteriores para que el lector pueda ver el desarrollo teórico allí realizado.

* [Informe TP1](InformeTP1.md)
* [Informe TP2](InformeTP2.md)

---

# 4. Resolución <a name="resolucion"></a>

---

# 5. Códigos de retorno <a name="retorno"></a>

Respetando lo pedido por el [enunciado](#retornoespecifico), los códigos de retorno se especifican a continuación.

*Debido a que siempre debemos devolver 0, no utilicé diversos códigos de error y me manejé con los mensajes de error de las excepciones para el debugging.*

## Servidor

| Código | Nombre | Descripción |
|--------|--------|-------------|
| 0 | SERVER_SUCCESS | *Ejecución exitosa* |
| 1 | SERVER_ERROR | *Ocurrió algún error* |
| 1 | SERVER_USAGE_ERROR | *Error en los argumentos recibidos* |

## Cliente

| Código | Nombre | Descripción |
|--------|--------|-------------|
| 0 | CLIENT_SUCCESS | *Ejecución exitosa* |
| 0 | CLIENT_ERROR | *Ocurrió algún error* |
| 0 | CLIENT_USAGE_ERROR | *Error en los argumentos recibidos* |


---

# 6. Conclusiones <a name="conclusiones"></a>



---