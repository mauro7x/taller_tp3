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
    * [Plan de resolución](#plan)
    * [Cliente](#client_model)
    * [Servidor](#server_model)
    * [Modelo final](#final_model)
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

- [TP1: Cliente/Servidor](#InformeTP1.md)
- [TP2: Threads](#InformeTP2.md)

Doy por explicadas las herramientas que allí detallo para realizar este trabajo y evitar redundancia.

---

# 4. Resolución <a name="resolucion"></a>

## Plan de resolución <a name="plan"></a>

Al igual que en trabajos anteriores, antes de ponerme a escribir código me dediqué a diseñar un plan de resolución que me permita ser eficiente y no escribir de más, así como intentar reducir al mínimo posible la generación de bugs y de código que luego deberá ser cambiado. Para esto, seguí lineamientos vistos en clase, que se pueden ver en detalle [aquí](#progreso.md).

Básicamente, el plan consiste en:

1. Realizar en papel un diseño completo de nuestro problema, con el objetivo de identificar **entidades** y clafisicarlas en distintas categorías, como podrían ser **objetos activos**, **recursos compartidos**, **canales de comunicación**, **lógica del negocio**, etc.

2. Una vez que tenemos el diseño básico en papel, procedemos a utilizar un concepto conocido como **proxy**. En esencia, utilizaremos **proxies** como objetos *fake*, puesto que quien los use creerá que hace una cosa, cuando en verdad hace otra.

    Por ejemplo: el cliente deberá utilizar alguna entidad para conectarse con el servidor y enviarle mensajes. Podríamos desde el primer momento diseñar una clase `Client` o `Protocol` o `ServerConnection` a través de la cual el cliente podría intercambiar mensajes con el servidor, pero es prácticamente seguro que escribiremos mucho código de más y tendremos muchos más bugs y dificultades a la hora de debuggear nuestro programa, pues estaríamos intentando hacer todo desde un principio. Aquí es donde surge el concepto de proxies: podemos crear una clase `ClientProxy` y que nuestro cliente **crea** que se comunica con el servidor, cuando en realidad esta clase **hardcodea** los valores de retorno que espera del servidor. Esto permite primero centrarse en resolver la lógica del programa, para luego con esta funcionando, implementar la funcionalidad que comunica ambos extremos.

    En esta etapa, entonces, diseñamos las **API** para el **cliente** y para el **servidor**, utilizando este concepto.

3. Ahora que tenemos nuestras clases proxy, resolvemos la **lógica del problema**. Es aquí cuando implementaremos las reglas del juego, el comportamiento de nuestras clases que componen el mismo, etc. Con el juego funcionando, pasamos a la próxima etapa.

4. Ahora poco a poco debemos **convertir nuestros objetos proxy en objetos reales**, que comuniquen nuestros extremos entre sí y utilicen múltiples hilos, etc. Primero, en esta etapa, nos ocuparemos de **serializar** la información. Para esto empezaremos por convertir nuestro `ProtocolProxy` en un verdadero `Protocol`, que serialice los mensajes a enviar.

5. Con la serialización funcionando, ahora sí, a nuestros protocolos les transformamos el `SocketProxy` en un **verdadero `Socket`**, para poder **conectar** a nuestros clientes con el servidor. Esta transición debería ser inmediata, pues si hicimos todo bien, sería tan simple como cambiar un `typedef int Socket` por un `#include "Socket.h"`. Para que esto funcione es esencial **diseñar bien nuestros objetos proxy**.

6. Lo único que falta ahora es introducir **multi-threading**, y nuevamente gracias a los objetos proxy esto debería ser tan sencillo como hacer que **nuestros objetos activos hereden de Thread**. Nuevamente, facilidades que nos brinda el concepto de proxy.

Explicado el plan seguido, en las próximas secciones mostraré detalles sobre qué **clases** diseñé para modelar las **distintas entidades del juego**.

## Cliente <a name="client_model"></a>

Empezaremos por el cliente. Este cliente es bastante sencillo, pues no necesitamos múltiples hilos de ejecución dado que lo único que debe hacer el cliente, en pseudo-código, es lo siguiente:

```
Mientras que el juego continue:
    leer un comando de entrada estandar.
    enviar el comando a través del protocolo al servidor.
    recibir una respuesta del servidor a través del protocolo.
    imprimir la respuesta por salida estandar.
    verificar si el juego continua.
Liberar recursos y salir.
```

Como vemos, es un **simple loop de ejecución continua** y no hay paralelizaciones claras que se puedan realizar, por lo que opto por no utilizar threads en este aplicativo.

### 1. Identificamos entidades:

Mientras que el **juego** continue:
- leer un **comando** de **entrada estándar**.
- enviar el *comando* a través del **protocolo** al **servidor**.
- recibir una **respuesta** del servidor a través del protocolo.
- imprimir la respuesta por **salida estándar**.
- verificar si el juego continua.

Liberar recursos y salir.

Vemos que para nuestro cliente, deberemos modelar las siguietnes entidades: juego, comando, algún streamer de entrada estandar, un protocolo, alguna forma de conectarnos con el servidor, almacenamiento de respuesta, salida estandar.

### 2. Diseño de entidades:

Implementaremos en base a las entidades identificadas en la sección anterior, las siguientes **clases**:

| Clase | Descripción | Detalles de implementación |
|-------|-------------|----------------------------|
| **ClientGame** | Encapsular la ejecución del juego. Permite evitar incluir lógica del negocio en nuestro *main*, generando código más legible y claro. Es el que se encargará de orquestrar la ejecución del aplicativo `client`. | Se ofrece un sólo método en su API: `play()`, que pone el juego a correr, implementando el pseudo código descripto previamente. |
| **CommandStreamer** | Encapsular la lectura de los datos de entrada en una sola clase. Leerá los comandos ingresados por el cliente y los creará alocandolos en el heap y devolviendo un puntero a los mismos. | Se generaliza la implementación para cualquier stream de datos pues lo recibe por parámetro al momento de su instanciación. |
| **Command** | **Interfaz** a ser implementada por los distintos comandos. Queremos que los comandos se sepan ejecutar para realizar su función principal. | Exige entonces, entre otras cosas, la implementación del `operator()` que permitirá ejecutarlo. Para que todos los comandos se puedan ejecutar polimórficamente, se exige que se invoque al operador `()` pasandole, entre otras cosas, el número secreto a adivinar así como un `std::string` pasado por referencia donde almacenar la respuesta. Devuelven un `state`. |
| **Guess** | Comando concreto, implementa **Command**. Su función será la de intentar adivinar un número concreto. | Compara el número recibido al momento de su instanciación con el número secreto recibido al momento de su ejecución. Guarda en el string recibido el resultado de la comparación. Siempre que se ejecuta gasta un intento. |
| **Surrender** | Comando concreto, implementa **Command**. Su función será la de rendirse. | Siempre devuelve `state=LOSS` y actualiza la respuesta en el string recibido. Termina la ejecución. |
| **Help** | Comando concreto, implementa **Command**. Su función será la de pedir ayuda sobre el uso permitido. | Siempre devuelve `state=CONTINUE` y actualiza la respuesta en el string recibido. Nunca gasta intentos. |
| **ClientProtocol** | Encapsular el protocolo y la conexión con el servidor, permitiendo desacoplar la inclusión del sistema **Cliente/Servidor** de la lógica del juego. El cliente deberá tratarlo como un canal de comunicación con el servidor. | Contiene un `Socket` que se conecta al servidor al momento de la instanciación del procotolo. Se sobrecargan los operadores `>>` para recibir y `<<` para enviar datos, a fines de facilitar la legibilidad del código. |

Además, utilizaremos las siguientes **abstracciones comunes** a varios trabajos prácticos:

| Clase | Descripción | Detalles de implementación |
|-------|-------------|----------------------------|
| **Exception** | Hereda de `std::exception`. Permite encapsular y agregar mensajes de error personalizados a las excepciones que nos provee C++, `std::exception`.  | Se permite herencia a fin de crear excepciones específicas para ciertos casos. |
| **Socket** | Abstracción creada en el TP1. Permite conectarnos con otro socket mediante distintos procolos, en este caso, **TCP**. | Contiene un `file descriptor` que se inicia y se conecta apenas se instancia el socket, proporcionando tres distintas maneras de instanciarlo: una para el *client-side*, y dos para el *server-side* (según se trate de un "*accepter socket*" o de un "*peer socket*"). |

Por último utilizaremos los siguientes **tipos definidos**:

| Tipo definido | Valores posibles | Detalles de implementación |
|---------------|------------------|----------------------------|
| **state** | `CONTINUE = 0`, `WIN = 1`, `LOSS = 2` | **Enum** utilizado como flags de ejecución de los comandos. Estos permiten a quien ejecute un comando saber como se debe proseguir tras su finalización. |

### 3. Armado del modelo final

Con las entidades previamente diseñadas, se procede al armado del modelo:

// diagrama del modelo CLIENTE


## Servidor <a name="server_model"></a>

Ahora es turno de diseñar el servidor. Acá la cosa se pone un poco más compleja, pues a priori parece que debemos realizar varias tareas de forma **paralela**: **aceptar** nuevos clientes, **procesar** los pedidos de los clientes, aceptar entrada externa a fines de **controlar** la ejecución del servidor.

Vemos entonces que en un primer análisis se identifican rápidamente **tres loops de ejecución**, y para afrontar esta problemática utilizaremos [**threads**](#InformeTP2.md).

Propongo para comenzar, el siguiente pseudo-código:
```
Crear estructura para almacenar resultados.
Procesar los números a utilizar recibidos por argumento.
Crear un hilo aceptador que acepte nuevos clientes*.
Poner dicho hilo a correr.
Mientras la entrada no sea 'q':
    leer comando por entrada estandar.
Dar la órden de cierre al hilo aceptador.
Esperar que el hilo aceptador termine.
Liberar recursos y salir.


// *: creación de hilo Aceptador.
```

Pseudo-código del hilo **Aceptador**:
```
Mientras que deba seguir aceptando clientes:
    aceptar un cliente y obtener su file descriptor.
    crear un nuevo juego para el cliente*².
    iniciar el juego para el cliente.
    agregar el juego a un contenedor de juegos activos.
    fijarse si hay juegos que hayan terminado y joinearlos*³.
Esperar que terminen los juegos activos*⁴.
Liberar recursos y salir.


// *²: creación de hilo para la ejecución de un juego.
// *³: join no bloqueante, no se espera que terminen.
// *⁴: join bloqueante, esperamos a que los juegos terminen naturalmente.
```

Pseudo-código para el hilo de cada **juego en ejecución**:
```
Iniciar el estado en: ejecutando.
Mientras el juego continue:
    recibir un comando del cliente a través del protocolo.
    ejecutar dicho comando.
    enviar respuesta al cliente a través del protocolo.
Modificar el estado a: finalizado.
```

Como vemos, hay tres loops de ejecución claros y para esto necesitaremos utilizar un hilo por cada uno de ellos, es decir:
- Un hilo para el **Servidor**,
- Un hilo para el **Aceptador**,
- Un hilo **PARA CADA CLIENTE que juegue** *(n hilos, con n clientes)*.

### 1. Identificamos entidades:

Para el **hilo principal del servidor**, vemos que necesitaremos: una entidad aceptadora de clientes (objeto activo), un parser de los números recibidos, una estructura para almacenar los resultados.

Para el **hilo aceptador**, necesitaremos: entidad juego del cliente (objeto activo), un contenedor de juegos activos.

Para cada **hilo de ejecución de juego**, necesitaremos: un estado de ejecución, conocer al objeto comando creado en [Cliente](#client_model), una estructura para almacenar la respuesta a enviar.

### 2. Diseño de entidades:

Implementaremos en base a las entidades identificadas en la sección anterior, las siguientes **clases**:

| Clase | Descripción | Detalles de implementación |
|-------|-------------|----------------------------|
| **Server** |  |  |
| **Numbers** |  |  |
| **ProtectedResults** |  |  |
| **Accepter** |  |  |
| **ServerGame** |  |  |
| **ServerProtocol** |  |  |

A su vez, re-utilizaremos la clase diseñada para el cliente: **Command**, así como las clases comunes descriptas previamente: **Socket** y **Exception**.


| **ClientGame** | Encapsular la ejecución del juego. Permite evitar incluir lógica del negocio en nuestro *main*, generando código más legible y claro. Es el que se encargará de orquestrar la ejecución del aplicativo `client`. | Se ofrece un sólo método en su API: `play()`, que pone el juego a correr, implementando el pseudo código descripto previamente. |
| **ClientProtocol** | Encapsular el protocolo y la conexión con el servidor, permitiendo desacoplar la inclusión del sistema **Cliente/Servidor** de la lógica del juego. El cliente deberá tratarlo como un canal de comunicación con el servidor. | Contiene un `Socket` que se conecta al servidor al momento de la instanciación del procotolo. Se sobrecargan los operadores `>>` para recibir y `<<` para enviar datos, a fines de facilitar la legibilidad del código. |

### 3. Armado del modelo final

Con las entidades previamente diseñadas, se procede al armado del modelo:

// diagrama del modelo SERVIDOR

## Modelo final <a name="final_model"></a>

// diagrama FINAL

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