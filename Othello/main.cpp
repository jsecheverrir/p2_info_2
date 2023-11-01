#include "clases.h"

int main(){
    tablero juego;
    char jugadores[2] = {'-','*'},jugador = ' ';
    int sin_movimientos = 0;        //cantidad de veces que se pueden quedar sin movimientos
    int contador = 0,cant_fichas_negro = 0,cant_fichas_blanco = 0;
    while (sin_movimientos < 2){
        jugador = (contador % 2 == 0)? jugadores[0] : jugadores[1] ;
        juego.calcular_mov_legales(jugador);
        if (juego.get_tamaño()==0){
            sin_movimientos++;
            contador ++;
        }
        else{
            sin_movimientos = 0;
            juego.mostrar_movimientos_posibles();
            juego.movimiento(jugador);
            juego.vaciar_movimientos();
            contador++;
        }
    }
    int ganador = '='; // Inicialmente no hay ganador
    // Contar las fichas en el tablero
    juego.contar_fichas(&cant_fichas_negro, &cant_fichas_blanco);
    if (cant_fichas_negro > cant_fichas_blanco) {
        cout << "El ganador es el Jugador 1 con " << cant_fichas_negro << " fichas." << endl;
        ganador = '-';
    } else if (cant_fichas_blanco > cant_fichas_negro) {
        cout << "El ganador es el Jugador 2 con " << cant_fichas_blanco << " fichas." << endl;
        ganador = '*';
    } else {
        cout << "Es un empate. Ambos jugadores tienen " << cant_fichas_negro << " fichas." << endl;
        ganador = '='; // Empate
    }
    // Solicitar nombres de los jugadores
    string nombreJugador1, nombreJugador2;
    cout << "Ingrese el nombre del Jugador -: ";
    cin >> nombreJugador1;
    cout << "Ingrese el nombre del Jugador *: ";
    cin >> nombreJugador2;
    // Guardar la partida
    guardarPartida(nombreJugador1, nombreJugador2, ganador);
    char verHistorial;
    cout << "Desea ver el historial de partidas jugadas? (S/N): ";
            cin >> verHistorial;
    if (verHistorial == 'S' || verHistorial == 's') {
        mostrarHistorial();
    }
    return 0;
}
