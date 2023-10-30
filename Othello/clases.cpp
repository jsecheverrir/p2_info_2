#include "clases.h"

tablero::tablero(){
    tab =  new char *[N];
    for (int i = 0; i < N; i++){
        tab[i] = new char [N];
        for (int j = 0; j < N; j++){
            if ((i == 3 && j == 3)|| (i == 4 && j == 4)) tab[i][j] = '*';           //posiciones pre-establecidad por el juego
            else if ((i == 3 && j == 4)|| (i == 4 && j == 3)) tab[i][j] = '-';
            else tab[i][j] = ' ';
        }
    }
    movimientos_posibles = nullptr;
    tamaño = 0;
    capacidad = 0;
}



void tablero::redimensionar(){
    if (capacidad == 0){
        // Si el arreglo está vacío, inicia con una capacidad de 2, ya que almacenamos pares de datos.
        capacidad = 2;
        movimientos_posibles = new int [capacidad];
    }
    else{
        capacidad *= 4;     //Para no generar muchos duplicados y tener espacio en reserva, cuadruplico el espacio reservado
        int  *new_arreglo = new int [capacidad];
        for (int i = 0; i < tamaño; i ++){      //generacion del duplicado de los elementos actuales
            new_arreglo[i] = movimientos_posibles[i];
        }
        delete [] movimientos_posibles;
        movimientos_posibles = new_arreglo;
    }
}

void tablero::push_back(int elemento){
    if(tamaño == capacidad){
        redimensionar();
    }
    movimientos_posibles[tamaño] = elemento;
    tamaño ++;
}

int tablero::get_tamaño(){
    return tamaño;
}

int tablero::get_capacidad(){
    return capacidad;
}

void tablero::vaciar_movimientos(){
    tamaño = 0;
    capacidad = 2;
    movimientos_posibles = new int [capacidad];
}

void tablero::imprimir_tablero(){
    cout << " ";
    for(char i = 'A'; i < 'A'+ N; i++){
        cout <<"   " << i;
    }
    cout << endl;
    for (int i = 0; i < N ; i++){
        cout << "  ";
        for (int j = 0; j < N ; j++){
            cout << "+===" ;
        }
        cout << "+\n";
        cout  << i+1<< " ";
        for (int j = 0; j < N ; j++){
            cout<< "| "  << tab[i][j]<< " ";
        }
        cout << "|" <<endl;
    }
    cout << "  ";
    for (int j = 0; j < N ; j++){
        cout << "+===" ;
    }
    cout << "+\n";
}

void tablero::calcular_mov_legales(char jugador){
    for (int fila = 0; fila < N ; fila ++){
        for (int columna = 0; columna < N ; columna ++){
            if (tab[fila][columna] == ' '){
                //evaluar si puedo generar un cambio en el tablero en esta posicion para el jugador selecto
                calcular_mov_valido(fila, columna, jugador);
            }
        }
    }
}

void tablero::calcular_mov_valido(int fila, int columna, char jugador){
    char otro_jugador = (jugador == '*')? '-':'*';
    int posiciones_adyacentes[8][2] ={{-1,1},{-1,0},{-1,1},         //Como las posiciones en un plano cartesiano
                                      {0,1},{0,-1},                 //estas son las 8 direcciones posibles de movimiento
                                      {1,1},{1,0},{1,-1}};
    for (int *par : posiciones_adyacentes ){
        //No evaluar ciertas posiciones adyacentes si me salgo del mapa, es decir, me encuentro en los bordes
        if (fila + par[0] > 7 || fila + par[0] || columna + par[1] > 7 || columna + par[1] < 0 ) continue;
        char caracter_evaluar = tab[fila+par[0]][columna+par[1]];

        if(caracter_evaluar == otro_jugador){       //evaluar que pueda aplicar sanduche
            int fila_modificar = fila + par[0];
            int columna_modificar = fila + par[1];

            while(caracter_evaluar == otro_jugador){        //evaluar el caso donde exista más de un caracter opuesto en línea

            }
        }
    }
}

void tablero::mostrar_movimientos_posibles(){
    for (int i = 0; i < tamaño; i ++){
        if(i % 2 == 0) cout << " (" << int_a_char(movimientos_posibles[i]);
        else cout << "," << movimientos_posibles[i] + 1<< ")";
    }
}

void tablero::hacer_movimiento(int fila, int columna){

}

void tablero::contar_fichas(){

}

bool tablero::terminacion(){



}

tablero::~tablero(){
    delete [] movimientos_posibles;
    for (int i = 0; i < N ; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
