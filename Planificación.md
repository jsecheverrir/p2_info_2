# Etapas de análisis.
* Planificación
	* Comprender las reglas del juego y las restricciones.
Diseñar la estructura de clases básicas.
Planificar la implementación y las tareas a realizar.

* Implementación del Juego
	* Crear clases para el tablero, jugadores y reglas del juego.
Implementar la lógica para realizar movimientos y mirar encierros "sandwich".
Desarrollar la visualización básica del tablero en la consola.
Realizar pruebas iniciales de las clases y la lógica.

* Finalización del Juego y Resultados
	* Implementar el manejo de fin de partida y el conteo de fichas.
Agregar la funcionalidad para guardar los resultados de cada partida en un archivo de texto.

* Añadir la opción de imprimir el historial de partidas en la consola.
	* Implementar manejo de excepciones para errores básicos.

* Pruebas y Ajustes
	* Realizar pruebas del juego.
Ajustar código según sea necesario.
Asegurar que todas las funciones esenciales funcionen correctamente.

* Video y Repositorio
	* Grabar video de YouTube 
Subir el código fuente al repositorio.

* Últimos Ajustes
	* Asegurar de que todo esté listo para la entrega.

*  Entrega
	* Enviar el enlace al repositorio y el informe a tu profesor antes de la fecha de entrega.

# Transcurso del Juego.
* Tablero 8x8 donde se ubican en las posiciones D4 y E5 fichas blancas y en D5 y E4 fichas negras.
![Captura de pantalla 2023-10-24 213148](https://github.com/Sebastian-8a/Parcial-2---Inform-tica-2/assets/129414377/dee0c46b-d65c-485d-9cdd-a8625890bbe8)
* Los jugadores se turnan para colocar una ficha de su color en el tablero. El jugador con las fichas negras comienza, la condición para que la
ficha pueda ser colocada es que genere un encierro tipo sandwich.
# Si un jugador no puede hacer un movimiento válido, pasa su turno.

#El juego continúa hasta que ningún jugador puede realizar movimientos válidos o el tablero se llena.

#Se cuentan las fichas de cada color en el tablero.

#El jugador con más fichas de su color gana la partida.


## Aspectos a tener en cuenta durante el desarrollo.
* Funcionalidades
	* Mostrar tablero por pantalla.
 	* Solicitud ubicación de ficha.
  	* Validación valor ingresado por consola.
  		* Tipo de caracteres ingresados.
  	 	* Validación cumplimiento de reglas.
	* Implementación cupmlimiento de reglas.
 	* Determinar fin del juego.
  	* Almacenado de scores.
  	* Almacenado histórico de partidas.
  	* Cambio de turno entre jugadores.
  	* Mostrar movimientos válidos.  
* Clases (Tenemos 2 opciones, a definir)

1 clase; juego: se considera crear simplemente una clase que represente todo el juego en sí, implementar dentro de esta clase los métodos y atributos que permitan el flujo de juego. Se plantea una sola clase ya que así podemos simplificar el diseño del código, que este sea mas fácil de manejar. También posibilita la gestión de componentes (jugadores, fichas) y reglas de juego (que dictan cada uno de los movimientos) en un solo lugar, al tenerlo compacto, tendremos un código mas legible y manejable. De usar esta sola clase, podríamos garantizar la encapsulación del codigo y así tendriamos todos los metodos en una sola unidad, y por último, al ser una sola clase, es mas fácil adaptarse a cambios de diseño, por ejemplo, que el usuario elija la dimensión del tablero.


2 clases; jugador y tablero: se piensa entonces la separación de la clase mencionada anteriormente para brindar modularidad al código, planteando 2 clases, una de jugador y otra de tablero, la de jugador tendría atributos como el nombre, el tipo de ficha, y la de tablero tendría entonces la estructura del tablero, dimensiones, estado de juego. Se dice entonces que la separacion del código en 2 clases seguiríamos el principio de separación de responsabilidades, donde cada clase tiene una tarea específica. También facilita la reutilización del código, ya que son clases bastante generales, y en cualquier juego podemos encontrar judores. A su vez, en casi todos los juegos podemos encontrar un tablero, que puede ser adaptado. De igual forma, a estar más separado el código, más legible será, ya que es evidente cual es la función de cada clase, y el seguimiento de nuestro código se favorece. Además tambien posibilita la detección de errores en el código.

# Desarrollo e ideas.
Crear un arreglo bidimensional 8*8 el cual representará nuestro tablero, con la posibilidad de escalarlo de forma parfamétrica con la intención de expandir el tamaño del tablero a futuro; En este caso usar una constante definida para este caso con el número 8, la cual será usada a lo largo de todo el programa. Llamemos a la constante N

Dicho tablero se mostrarán las filas desde la A a la 'A' + N, en el caso del tablero a realizar será hasta la letra H, y las filas irán desde el número 1 al 8, esto será para dar la posibilidad de que el usuario ingrese la posición en la que desea colocar su ficha, para nosotros se comportará como referenciación de índices. Ejm; A2 sería [0][1] ya que la A es el primer caracter alfabético y el 1 el índice correspondiente al número 2.

Pensar y establecer un formato para el ingreso de información por consola, definir tanto el tipo de dato donde se almacenará el dato y la conversión adecuada para acceder a la ubicación adecuada de la estructura.

Establecer en el arreglo las posiciones que van predefinidas en el juego.

Generar **Algoritmo que encuentre caminos posibles**, inicialmente siempre serán los mismos, pero conforme el desarrollo se irá escalando a su ejecución indiferente de la condición del tablero, allí irán **Incluidas las reglas** debido a que para considerar un móvimiento válido es necesario evaluarlas.

Una vez tengo los movimientos válidos, muestro el tablero y los movimientos por pantalla para solicitar una entrada.
	 
* Debo validar que la entrada sea con el formato establecido. Ej "G4" primer caracter debe ser una letra, segundo caracter debe ser un numero ambos rangos determinados por el tablero.
	 
* Validar que la entrada se encuentre en los movimientos válidos.
De ser válida la entrada, se procede a hacer el movimiento y se actualiza el tablero, si no es valido se debe pedir entrada nuevamente.

Una vez actualizado el tablero, se pide movimiento al siguiente jugador. Seguimos el mismo proceso hasta que no hayan movimientos válidos (que el movimiento no genere un encierro tipo sandwich o que el tablero ya no tenga lugar para más fichas nuevas).

Para este momento debemos tener un ganador, se procede a recorrer el tablero con un puntero que cuente el numero de fichas de cada jugador para asi definir el ganador. 

Cuando sabemos quien ganó, pedimos nombres de jugadores y almacenamos en un archivo txt (sujeto a cambios), la partida para tener un historial de juego.

Implementar función para leer el archivo que almacenará las partidas jugadas anteriormente, y muestre al usuario de forma amigable dicho historial.






Caminos posibles -> Se le debe pasar la estructura.



