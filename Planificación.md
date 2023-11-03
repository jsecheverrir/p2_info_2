# Etapas de análisis.
* Análisis
	* Contextualización del problema:
	Se debe crear un programa que permita disfrutar del juego de mesa Othello, también conocido como Reversi. Es un juego de mesa 		para dos jugadores que se juega en un tablero de 8x8. El objetivo del juego es tener la mayor cantidad de fichas de tu color en 	el tablero cuando termine la partida
	Aunque aparentemente simple, Othello es un juego que involucra una estrategia profunda y desafía a los jugadores a anticipar y 		planificar sus movimientos con precisión.

* Consideraciones para abordar el problema
	- Comprender las reglas del juego y las restricciones.
	- Diseñar la estructura de clases básicas.
	- Planificar la implementación y las tareas a realizar.

* Implementación del Juego
	- Crear clases para el tablero, jugadores y reglas del juego.
	- Implementar la lógica para realizar movimientos y mirar encierros "sandwich".
	- Desarrollar la visualización básica del tablero en la consola.
	- Realizar pruebas iniciales de las clases y la lógica.
	- Realizar validaciones necesarias para garantizar el flujo de juego

* Finalización del Juego y Resultados
	- Implementar el manejo de fin de partida y el conteo de fichas.
	- Agregar la funcionalidad para guardar los resultados de cada partida en un archivo de texto.
 	- Añadir la opción de imprimir el historial de partidas en la consola.
	- Implementar manejo de excepciones para errores básicos.

* Pruebas y Ajustes
	- Realizar pruebas del juego.
	- Ajustar código según sea necesario.
	- Asegurar que todas las funciones esenciales funcionen correctamente.

* Video y Repositorio
	- Grabar video de YouTube 
	- Subir el código fuente al repositorio.

* Últimos Ajustes
	- Asegurar de que todo esté listo para la entrega.

*  Entrega
	- Enviar el enlace al repositorio y el informe a tu profesor antes de la fecha de entrega.

# Transcurso del Juego.
* Tablero 8x8 donde se ubican en las posiciones D4 y E5 fichas blancas y en D5 y E4 fichas negras.
![Captura de pantalla 2023-10-24 213148](https://github.com/Sebastian-8a/Parcial-2---Inform-tica-2/assets/129414377/dee0c46b-d65c-485d-9cdd-a8625890bbe8)
* Los jugadores se turnan para colocar una ficha de su color en el tablero. El jugador con las fichas negras comienza, la condición para que la
ficha pueda ser colocada es que genere un encierro tipo sandwich.
* Si un jugador no puede hacer un movimiento válido, pasa su turno.

* El juego continúa hasta que ningún jugador puede realizar movimientos válidos o el tablero se llena.

* Se cuentan las fichas de cada color en el tablero.

* El jugador con más fichas de su color gana la partida.


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

* 1 clase
	* Para diseñar el juego, se considera crear simplemente una clase que represente todo el juego en sí. (clase Othello)
 	* Implementar dentro de esta clase los métodos y atributos que permitan el flujo de juego.
  	* Se plantea una sola clase ya que así podemos simplificar el diseño del código, que sea más fácil de manejar.
   	* También posibilita la gestión de componentes (jugadores, fichas) y reglas de juego (que dictan cada uno de los movimientos) en 	un solo lugar.
    	* Al tenerlo compacto, tendremos un código más legible y manejable.
     	* De usar esta sola clase, podríamos garantizar la encapsulación del código.
      	* Por último, al ser una sola clase, es más fácil adaptarse a cambios de diseño, por ejemplo, que el usuario elija la dimensión 	del tablero.


* 2 clases
  	* Se piensa entonces la separación de la clase mencionada anteriormente para brindar modularidad al código planteando 2 clases, 	una de jugador y otra de tablero.
  	* La clase de jugador tendría atributos como el nombre y el tipo de ficha.
  	* La clase de tablero tendría la estructura del tablero, dimensiones y estado de juego.
  	* Se dice entonces que la separación del código en 2 clases seguiría el principio de separación de responsabilidades, donde cada 	clase tiene una tarea específica.
  	* También facilita la reutilización del código, ya que son clases bastante generales, y en cualquier juego podemos encontrar 		jugadores.
  	* A su vez, en casi todos los juegos podemos encontrar un tablero, que puede ser adaptado.
  	* De igual forma, al estar más separado el código, será más legible, ya que es evidente cuál es la función de cada clase, y el 		seguimiento de nuestro código se favorece.
  	* Además, también posibilita la detección de errores en el código.
  	  
  	
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

* Una vez actualizado el tablero, se pide movimiento al siguiente jugador. Seguimos el mismo proceso hasta que no hayan movimientos válidos (que el movimiento no genere un encierro tipo sandwich o que el tablero ya no tenga lugar para más fichas nuevas).

* Para este momento debemos tener un ganador, se procede a recorrer el tablero con un puntero que cuente el numero de fichas de cada jugador para asi definir el ganador. 

* Cuando sabemos quien ganó, pedimos nombres de jugadores y almacenamos en un archivo txt (sujeto a cambios), la partida para tener un historial de juego.

* Implementar función para leer el archivo que almacenará las partidas jugadas anteriormente, y muestre al usuario de forma amigable dicho historial.


Caminos posibles -> Se le debe pasar la estructura.

* 1 clase:
Esqueleto del código:
#include <iostream>
using namespace std;
		
class tablero{
private:
	char **tab;		//Tablero
	int *movimientos_posibles;      //almacena par de datos en forma de fila, columna, fila,...
	int *direccion;                 //almacena par de coordenadas que indican dirección del movimiento
	int capacidad;          //capacidad de movimientos posibles
	int tamaño;             //cantidad de elementos

public:
	tablero();
	~tablero();
	
	void redimensionar();
	void push_back_mov(int elemento, int dir);
	int get_tamaño();
	void vaciar_movimientos();
	void imprimir_tablero();			//Función que imprime el tablero de juego
	void calcular_mov_legales(char jugador);                  	//Comprobar los 8 caminos adyacentes para todas las fichas
	void calcular_mov_valido(int fila, int columna,char jugador);               //Solo para una ficha y un camino, validar si en esa 	ficha y 										camino es posible ese movimiento
	void mostrar_movimientos_posibles();             //muestra el atributo movimientos_posibles
	void movimiento(char jugador);
	void hacer_movimiento(int fila, int columna, int indice, char jugador);                 //modificar tablero con el movimiento
	
	
	void contar_fichas(int *cant_fichas_negro, int *cant_fichas_blanco);                             //Cuenta fichas de cada jugador

}



  	* Por qué usar este esqueleto:
	1. Estructura Básica: El código establece una estructura básica para el juego. Define una clase juego que contiene métodos para 	inicializar el tablero, verificar movimientos válidos, realizar movimientos, determinar el final del juego y alternar entre 		jugadores.
	2. Utiliza una matriz dinámica (char **tab) para representar el tablero. Esto es importante para el juego de Othello, ya que el 	tablero es una parte central de la mecánica del juego. Esta matriz se crea de manera dinámica en el constructor y se libera en 		el destructor, lo que es un buen enfoque para la gestión de memoria.
	3. El código proporciona esqueletos de métodos necesarios para la finalización exitosa del juego. Estos métodos son 			fundamentales para la lógica del juego y pueden ser completados con las reglas específicas de Othello.


 	* Función a función
	 1. Constructor y Destructor de juego:
		Constructor:
		Reserva memoria dinámica para el tablero, una matriz dinámica de 8x8.
		Inicializar los caracteres p1 y p2 para representar a los jugadores.
		Llamar a la función tablero() para inicializar el tablero.
	Destructor:
		Liberar la memoria dinámica utilizada por el tablero.
	
* Descripcion de métodos: 
	1. tablero(): Constructor de la clase, inicializa el tablero de juego y otros atributos.
	2. ~tablero(): Destructor de la clase, se encarga de liberar la memoria asignada dinámicamente para el tablero y otros atributos.
	3. redimensionar(): Método para redimensionar el espacio de memoria asignado para almacenar movimientos posibles.
	4. push_back_mov(int elemento, int dir): Agrega un movimiento posible al conjunto de movimientos.
	5. get_tamaño(): Obtiene el tamaño actual del conjunto de movimientos.
	6. vaciar_movimientos(): Limpia la lista de movimientos.
	7. imprimir_tablero(): Imprime el tablero de juego en la consola.
	8. calcular_mov_legales(char jugador): Calcula los movimientos legales para un jugador en el tablero.
	9. calcular_mov_valido(int fila, int columna, char jugador): Evalúa si un movimiento es válido para una ficha en una posición 		dada.
	10. mostrar_movimientos_posibles(): Muestra en la consola los movimientos posibles.
	11. movimiento(char jugador): Solicita al usuario un movimiento y lo procesa en el tablero.
	12. hacer_movimiento(int fila, int columna, int indice, char jugador): Modifica el tablero con el movimiento realizado por un 		jugador.
	13. contar_fichas(int *cant_fichas_negro, int *cant_fichas_blanco): Cuenta las fichas de cada jugador en el tablero.


* Decisiones de atributos de la clase 

	Miembros en public:
	Constructor y Destructor (tablero() y ~tablero()): Estos métodos son típicamente públicos porque deben ser accesibles desde 		fuera de la clase para crear y destruir objetos de la clase tablero. Los usuarios del objeto necesitan poder crear instancias 		del juego y liberar los recursos asociados cuando ya no son necesarios.	
	Métodos privados (tablero(), verif_movimiento(), movi(), terminacion(), jugadores()): Estos métodos son privados porque son 		utilizados internamente por la clase para implementar la lógica del juego. Los usuarios del objeto de juego no necesitan conocer 	los detalles de implementación de estas funciones, ya que su interacción con el juego se realiza a través de la función pública 	jugar(). Mantener estos métodos como privados ayuda a encapsular la lógica del juego y evita el acceso no deseado a partes 		internas de la clase.

* Problemas afrontados en del desarrollo
  	- Diseño y Estructura del Proyecto: Decidir cómo organizar y estructurar el proyecto para manejar eficientemente las clases y 		los componentes del juego
  	- Implementación de las Reglas del Juego: Garantizar que las reglas del juego, incluyendo la colocación de fichas y las 		inversiones de fichas, se implementen 	de manera correcta
  	- Actualizacion correcta del tablero despues de cada movimiento
  	- Algoritmos de Búsqueda de Movimientos Legales: Desarrollar algoritmos para determinar los movimientos legales disponibles en 		el tablero, lo que puede ser 	complejo debido a las reglas de Othello.
  	- Manejo de la Memoria: Evitar problemas de gestión de memoria, como fugas de memoria, al trabajar con estructuras de datos 		dinámicas, como el tablero.
  	- Registro de Partidas: Implementar correctamente la funcion que guarda registro de las partidas, al igual que mostrar 			amigablemente por consola el historial 	de partidas
