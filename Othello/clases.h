#ifndef CLASES_H
#define CLASES_H

#include "funciones.h"

#define N 8


class tablero{
private:
    char **tab;		//Tablero
    char p1, p2;	//Jugadores
    int *movimientos_posibles;      //almacena par de datos en forma de fila, columna, fila,...
    int capacidad;          //capacidad de movimientos posibles
    int tamaño;             //cantidad de elementos

public:
    tablero();
    ~tablero();

    void redimensionar();
    void push_back(int elemento);
    int get_tamaño();
    int get_capacidad();
    void vaciar_movimientos();

    void imprimir_tablero();			//Función que imprime el tablero de juego
    void calcular_mov_legales();                  	//Comprobar los 8 caminos adyacentes para todas las fichas
    void calcular_mov_jugador(char jugador);               //Solo para una ficha y un camino, validar si en esa ficha y camino es posible ese movimiento
    void mostrar_movimientos_posibles();             //muestra el atributo movimientos_posibles
    //validar entrada por consola se encuentre dentro de los movimientos posibles
    void hacer_movimiento(char mov_posible);                 //modificar tablero con el movimiento

    void vaciar_movimientos_posibles();               //

    void contar_fichas();                             //Cuenta fichas de cada jugador
    bool terminacion();				//Verifica si el juego ha terminado
};






#endif // CLASES_H
