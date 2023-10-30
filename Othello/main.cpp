#include "clases.h"

int main(){
    tablero prueba;
    char jugadores[2] = {'-','*'};
    char jugador = ' ';
    int sin_movimientos = 0;        //cantidad de veces que se pueden quedar sin movimientos
    int contador = 0;
    prueba.imprimir_tablero();
    prueba.calcular_mov_legales('-');
    prueba.mostrar_movimientos_posibles();
    /*
    while (sin_movimientos < 2){
        jugador = (contador % 2 == 0)? jugadores[0] : jugadores[1] ;
        prueba.calcular_mov_legales(jugador);
        if (prueba.get_tamaño()==0){
            sin_movimientos++;
        }
        else{
            sin_movimientos = 0;

        }

    }*/
    /*


prueba.imprimir_tablero();
    prueba.push_back(0);
    prueba.push_back(1);
    prueba.push_back(1);
    prueba.push_back(2);
    prueba.push_back(2);
    prueba.push_back(3);
    prueba.push_back(3);
    prueba.push_back(4);
    prueba.push_back(4);
    prueba.push_back(5);
    prueba.push_back(5);
    prueba.push_back(6);
    prueba.mostrar_movimientos_posibles();




    prueba.mostrar_movimientos_posibles();
    cout << "\n";
    cout << prueba.get_capacidad();
    cout << "\n";


*/


    return 0;
}
