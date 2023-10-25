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
# Aquí Juana va a terminar de poner el desarrollo y reglas del juego





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
* Clases



# Desarrollo e ideas.
Crear un arreglo bidimensional 8*8 el cual representará nuestro tablero, con la posibilidad de escalarlo de forma parfamétrica con la intención de expandir el tamaño del tablero a futuro; En este caso usar una constante definida para este caso con el número 8, la cual será usada a lo largo de todo el programa. Llamemos a la constante N

Dicho tablero se mostrarán las filas desde la A a la 'A' + N, en el caso del tablero a realizar será hasta la letra H, y las filas irán desde el número 1 al 8, esto será para dar la posibilidad de que el usuario ingrese la posición en la que desea colocar su ficha, para nosotros se comportará como referenciación de índices. Ejm; A2 sería [0][1] ya que la A es el primer caracter alfabético y el 1 el índice correspondiente al número 2.

Pensar y establecer un formato para el ingreso de información por consola, definir tanto el tipo de dato donde se almacenará el dato y la conversión adecuada para acceder a la ubicación adecuada de la estructura.

Establecer en el arreglo las posiciones que van predefinidas en el juego.

Generar **Algoritmo que encuentre caminos posibles**, inicialmente siempre serán los mismos, pero conforme el desarrollo se irá escalando a su ejecución indiferente de la condición del tablero, allí irán **Incluidas las reglas** debido a que para considerar un móvimiento válido es necesario evaluarlas.

Una vez tengo los movimientos válidos, muestro el tablero y los movimientos por pantalla para solicitar una entrada.
	 
* Debo validar que la entrada sea con el formato establecido.
	 
* Validar que la entrada se encuentre en los movimientos válidos.









  Caminos posibles -> Se le debe pasar la estructura.
