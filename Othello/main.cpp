#include "clases.h"

int main(){
    tablero prueba;
    char jugadores[2] = {'-','*'},jugador = ' ';
    int sin_movimientos = 0;        //cantidad de veces que se pueden quedar sin movimientos
    int contador = 0,cant_fichas_negro = 0,cant_fichas_blanco = 0;
    while (sin_movimientos < 2){
        jugador = (contador % 2 == 0)? jugadores[0] : jugadores[1] ;
        prueba.calcular_mov_legales(jugador);
        if (prueba.get_tamaño()==0){
            sin_movimientos++;
            contador ++;
        }
        else{
            sin_movimientos = 0;
            prueba.mostrar_movimientos_posibles();
            prueba.movimiento(jugador);
            prueba.vaciar_movimientos();
            contador++;
        }
    }
    prueba.contar_fichas( & cant_fichas_negro, &cant_fichas_blanco);

    return 0;
}
