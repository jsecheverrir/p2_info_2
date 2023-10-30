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
    p1 = '*';
    p2 = '-';
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

void tablero::mostrar_movimientos_posibles(){
    for (int i = 0; i < tamaño; i ++){
        if(i % 2 == 0) cout << " (" << int_a_char(movimientos_posibles[i]);
        else cout << "," << movimientos_posibles[i] + 1<< ")";
    }
}


tablero::~tablero(){
    delete [] movimientos_posibles;
    for (int i = 0; i < N ; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
