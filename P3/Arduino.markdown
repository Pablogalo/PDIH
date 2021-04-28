# Práctica 3.- Experimentación con Arduino
### Hecho por: Pablo García López

## 1.- Introducción
Para esta práctica se ha trabajado con TinkerCad, un simulador del hardware Arduino con el que poder probar distintos circuitos. Los ejercicios propuestos van a ser descritos en las distintas secciones de esta memoria, incluyendo elementos necesarios para el circuito, montaje del circuito, código y un ejemplo de ejecución. 

## 2.- Seminario
### 2.1.- Ejercicio 1
En este ejercicio, se pide implementar un programa que encienda y apague alternativamente dos LEDs con un intervalo de 1,5 segundos. Los materiales necesarios son:
- 2 LEDs, uno rojo y otro verde.
- 2 resistencias de 220 ohmios.

Para el montaje del circuito debemos conectar el cátodo de cada uno de los LEDs a tierra y el ánodo a una de las resistencias, conectando a su vez el otro terminal de la resistencia a una salida digital de la placa Arduino (en nuestro caso 12 y 13). El montaje lo podemos observar en la siguiente imagen:

![Circuito-Ej1-S.png](https://i.postimg.cc/pTJNYh6p/Circuito-Ej1-S.png)

El código asociado a este ejercicio es el siguiente:

![Codigo-Ej1-S.png](https://i.postimg.cc/hGCZSL68/Codigo-Ej1-S.png)

En la inicialización (función setup()) se establecen los pins 12 y 13 de la placa como salidas. En la función principal del código (función loop()) se enciende uno de los LEDs y se apaga el otro, se esperan 1,5 segundos y se invierten, es decir, el que estaba apagado se enciende y viceversa, para finalmente esperar de nuevo 1,5 segundos y repetir todo de nuevo, encendiendo así los LEDs alternativamente. El funcionamiento de este circuito lo podemos observar en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448188-1e5e8a00-a859-11eb-8081-e10eca0ebc35.mp4

### 2.2.- Ejercicio 2
Este ejercicio consiste en crear un programa que encienda un LED cuando se pulse un botón. Los materiales necesarios para su realización son:
    - Un LED.
    - Un pulsador.
    - 2 resistencias, una de 220 ohmios y otra de 10 kiloohmios.

El montaje del circuito lo vamos a dividir en dos partes:
    - Por una parte, debemos conectar el ánodo del LED a la salida digital 13 de la placa y el cátodo a la resistencia de 220 ohmios, la cual la conectamos a su vez a tierra.
    - Respecto al botón, debemos conectar 2 de sus patillas contiguas una a 5V y otra a la resistencia de 10 kiloohmios, conectando esta a tierra. La patilla del lado opuesto del pulsador a la que está conectada la resistencia la conectamos a una salida digital de Arduino (en nuestro caso a la 7).
El circuito completo lo podemos observar en la siguiente imagen:

![Circuito Ej2-S](https://user-images.githubusercontent.com/56371721/116448264-31715a00-a859-11eb-9550-1218c9a0f99b.png)

El código asociado al circuito lo podemos observar en la siguiente imagen:

![Codigo Ej2-S](https://user-images.githubusercontent.com/56371721/116448280-37ffd180-a859-11eb-8d4b-42e155148cce.png)

Para comenzar, se declara la variable button de tipo int para representar el valor del pulsador. En la inicialización se fija el pin 13 como salida y el pin 7 como entrada. En la función principal, se lee en la variable button el valor del pulsador y si es HIGH (botón pulsado) se enciende el LED por medio del pin 13 y si no (es decir, el valor de button es LOW) se apaga el LED. Como esto se ejecuta de manera infinita, el LED se va encendiendo o apagando según pulsamos o no el botón. Adicionalmente, al final de la función loop se hace una espera de 10 milisegundos para que la simulación tenga un mejor rendimiento (visto en los tutoriales de TinkerCad). Este funcionamiento lo podemos observar en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448293-3f26df80-a859-11eb-8032-3f8fdda7a3d2.mp4

## 3.- Práctica
### 3.1.- Ejercicio 1
Este ejercicio es similar al ejercicio 1 del seminario, por lo que para su realización necesitamos los mismos materiales más otro LED y otra resistencia de 220 ohmios. El montaje también es similar pero añadiendo otro subcircuito de resistencia y LED similar al descrito en el apartado relativo a este ejercicio. El circuito lo podemos observar en la siguiente imagen:

![Circuito Ej1-P](https://user-images.githubusercontent.com/56371721/116448340-4f3ebf00-a859-11eb-9d1d-41e72ae8a892.png)

El código asociado al circuito también es similar al del ejercicio 1 del seminario pero añadiendo un pin más, por lo que es necesario añadir un bloque de código más que encienda el nuevo LED, del mismo modo que lo hacemos en dicho ejercicio. El código descrito es el siguiente:

![Codigo Ej1-P](https://user-images.githubusercontent.com/56371721/116448376-582f9080-a859-11eb-8320-a60b42caf103.png)

El circuito en funcionamiento lo podemos ver en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448389-5c5bae00-a859-11eb-8e56-c9f96224197d.mp4

### 3.2.- Ejercicio 2
Para este ejercicio hay que crear un programa en el que haya 3 LEDs, uno rojo, otro amarillo y otro verde y un botón que, al pulsarlo, encienda el LED rojo y apague los LEDs amarillo y verde. Por tanto, los materiales necesarios para este circuito son:
    - 3 LEDs, rojo, amarillo y verde.
    - 3 resistencias de 220 ohmios y otra de 10 kiloohmios.
    - Un pulsador.

El montaje de este ejercicio es similar al de otros ejercicios descritos anteriormente. La explicación la dividimos en dos partes:
    - En una primera parte debemos crear el mismo circuito de 3 LEDs descrito en el apartado anterior. 
    - A continuación, debemos montar también el circuito del pulsador descrito en el apartado 2.2 de esta memoria.
El circuito completo lo podemos observar en la siguiente imagen:

![Circuito Ej2-P](https://user-images.githubusercontent.com/56371721/116448422-641b5280-a859-11eb-86cc-1dcd01d301cb.png)

El código asociado a este circuito también es similar al del apartado 2.2 de esta memoria, con las únicas diferencias de que tenemos que fijar dos pins más como salida en la función de inicialización y en la función principal, si el botón está pulsado, debemos activar el pin asociado al LED rojo y desactivar los otros dos y viceversa si el botón no está pulsado. Este código lo podemos observar en la siguiente imagen:

![Codigo Ej2-P](https://user-images.githubusercontent.com/56371721/116448437-69789d00-a859-11eb-8c0f-4e951e49c7b3.png)

Un ejemplo del funcionamiento de este circuito es el siguiente:

https://user-images.githubusercontent.com/56371721/116448451-6da4ba80-a859-11eb-94ed-9394ae8bf4a0.mp4

### 3.3.- Luces del coche fantástico
Para este ejercicio hay que recrear las luces de "El coche fantástico" con 4 LEDs encendiéndose secuencialmente. Se han realizado dos pequeñas versiones de esto, que se van a describir de manera separada.

#### 3.3.1.- Primera aproximación
Los materiales necesarios para la primera versión de este ejercicio son:
    - 4 LEDs de color rojo.
    - 4 resistencias de 220 ohmios.

El montaje del circuito es muy sencillo, ya que es similar al del apartado 2.1 de esta memoria. Conectamos los cátodos de los LEDs a tierra y los cátodos a las resistencias, conectando estas a su vez cada una a una salida digital de la placa Arduino, como podemos observar en la siguiente imagen:

![Circuito coche 1](https://user-images.githubusercontent.com/56371721/116448478-772e2280-a859-11eb-8345-dda910ce29c4.png)

El código asociado al circuito descrito es el siguiente:

![Codigo coche 1](https://user-images.githubusercontent.com/56371721/116448498-7c8b6d00-a859-11eb-9943-f4119ea5f07b.png)

Por simplicidad en el código, antes de la función de inicialización declaramos un vector de int de 4 elementos, inicializando cada una de sus componentes con el número de las salidas digitales de Arduino a las que hemos conectado las resistencias. En la función setup() declaramos todos estos pins como salidas. En la función principal realizamos dos bucles; el primero de ellos (4 iteraciones, ya que tenemos 4 LEDs) recorre el vector de manera ascendente, encendiendo en cada iteración un LED, esperando 50 milisegundos y apagándolo para volver a esperar 50 milisegundos. El segundo bucle es análogo pero recorriendo el vector de manera descendente. Estos dos bucles provocan que los LEDs se vayan encendiendo de izquierda a derecha y luego de derecha a izquierda, simulando así las luces de "El coche fantástico".

Este funcionamiento lo podemos observar en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448518-82814e00-a859-11eb-9e2b-0448c720f865.mp4

#### 3.3.2.- Segunda aproximación
Se ha creado un segundo circuito para este ejercicio, similar a la primera versión pero con el doble de LEDs. El código asociado a esta segunda versión es el siguiente:

![Codigo coche 2](https://user-images.githubusercontent.com/56371721/116448568-8f05a680-a859-11eb-85f4-63c98653d5ba.png)

Es similar al del apartado anterior, con 2 pequeñas modificaciones:
    - Como tenemos 8 LEDs en lugar de 4, el vector ahora tiene 8 componentes.
    - En los dos bucles de la función principal, ahora en lugar de encender un LED, encendemos el LED que toca en cada iteración y a su vez encendemos el LED de la izquierda y de la derecha, apagando al final de la iteración el LED "último" (es decir, si vamos de izquierda a derecha apagamos el LED que está situado a la izquierda de los 3 encendidos y si vamos de derecha a izquierda apagamos el LED que esté a la derecha).

Esta segunda versión la podemos observar en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448586-91680080-a859-11eb-9a3f-6923eea3b665.mp4

En mi opinión, al tener más LEDs e ir encendiéndolos de la manera descrita anteriormente provoca que las luces sean más similares a las de "El coche fantástico" y por lo tanto es un resultado más satisfactorio.

### 3.4.- Alarma por detección de presencia
Para este ejercicio se ha simulado un pequeño circuito con un sensor de movimiento que enciende un LED rojo si detecta alguna presencia en su rango. Para su realización necesitamos:
    - Un LED rojo.
    - Una resistencia de 220 ohmios.
    - Un sensor PIR.

Para el montaje del circuito debemos realizar el mismo montaje del LED descrito en el apartado 2.1 y respecto al sensor, debemos conectar su patilla de tierra a un pin de tierra de Arduino, su patilla de potencia a 5 voltios y su patilla de señal a una salida digital de Arduino, como podemos ver en la siguiente imagen:

![Circuito alarma](https://user-images.githubusercontent.com/56371721/116448622-9cbb2c00-a859-11eb-895a-471ed47ae26a.png)

Su código asociado es:

![Codigo alarma](https://user-images.githubusercontent.com/56371721/116448637-a04eb300-a859-11eb-955a-541bd40def58.png)

En primer lugar, declaramos la variable PIR de tipo int para recoger el valor que está detectando el sensor. En la función de inicialización declaramos el pin del LED como salida y el pin del sensor como entrada. En la función principal leemos el valor que está tomando el sensor y si este es HIGH (es decir, está detectando algo dentro de su rango) encendemos y apagamos el LED, simulando así que salta la alarma. Este funcionamiento lo podemos observar en el siguiente vídeo:

https://user-images.githubusercontent.com/56371721/116448783-c83e1680-a859-11eb-98a3-6a13630a76d1.mp4
