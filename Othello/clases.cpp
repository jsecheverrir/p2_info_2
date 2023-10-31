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
    direccion = nullptr;
    tamaño = 0;
    capacidad = 0;
}

void tablero::mostrar_movimientos_pos(){
    for (int i = 0; i < tamaño; i ++){
        cout << " " << movimientos_posibles[i];
    }
}

void tablero::redimensionar(){
    if (capacidad == 0){
        // Si el arreglo está vacío, inicia con una capacidad de 2, ya que almacenamos pares de datos.
        capacidad = 2;
        movimientos_posibles = new int [capacidad];
        direccion = new int [capacidad];
    }
    else{
        capacidad *= 4;     //Para no generar muchos duplicados y tener espacio en reserva, cuadruplico el espacio reservado
        int  *new_arreglo = new int [capacidad];
        int  *new_direccion = new int [capacidad];
        for (int i = 0; i < tamaño; i ++){      //generacion del duplicado de los elementos actuales
            new_arreglo[i] = movimientos_posibles[i];
            new_direccion[i] = direccion[i];
        }
        delete [] movimientos_posibles;
        delete [] direccion;
        movimientos_posibles = new_arreglo;
        direccion = new_direccion;
    }
}

void tablero::push_back_mov(int elemento){
    if(tamaño == capacidad){
        redimensionar();
    }
    movimientos_posibles[tamaño] = elemento;
    tamaño ++;
}

void tablero::push_back_dir(int elemento){
    if(tamaño == capacidad){
        redimensionar();
    }
    direccion[tamaño] = elemento;
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
    movimientos_posibles = nullptr;
    direccion = nullptr;
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

void tablero::calcular_mov_valido(const int fila,const int columna, char jugador){
    char otro_jugador = (jugador == '*')? '-':'*';
    int posiciones_adyacentes[8][2] ={{-1,1},{-1,0},{-1,1},         //Como las posiciones en un plano cartesiano
                                      {0,1},{0,-1},                 //estas son las 8 direcciones posibles de movimiento
                                      {1,1},{1,0},{1,-1}};
    for (int *par : posiciones_adyacentes ){
        //No evaluar ciertas posiciones adyacentes si me salgo del mapa, es decir, me encuentro en los bordes
        if (fila + par[0] > 7 || fila + par[0] < 0|| columna + par[1] > 7 || columna + par[1] < 0 )
            continue;
        char caracter_evaluar = tab[fila+par[0]][columna+par[1]];       //evaluar si el estado del caracter, es decir si es oponente o propio

        if(caracter_evaluar == otro_jugador){       //evaluar que pueda aplicar sanduche
            int fila_temp = fila + par[0];
            int columna_temp = columna + par[1];

            while(caracter_evaluar == otro_jugador){        //evaluar el caso donde exista más de un caracter opuesto en línea
                fila_temp += par[0];          //Moverme en la misma dirección para evaluar
                columna_temp +=  par[1];
                if (fila_temp > 7 || fila_temp < 0|| columna_temp > 7 || columna_temp < 0 )    //revisar que no me salga del tablero
                    break;
                caracter_evaluar = tab[fila_temp][columna_temp];
            }
            if (caracter_evaluar == jugador){
                push_back_mov(fila);
                push_back_mov(columna);
                push_back_dir((par[0]*-1));
                push_back_dir((par[1]*-1));
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

void tablero::movimiento(char jugador){
    string ingresado;
    bool validacion = false;
    int fila = 0, columna = 0;
    system("cls");
    while (validacion != true){
        imprimir_tablero();
        cout << "\nLos movimientos posibles para " <<jugador<<" son: ";
        mostrar_movimientos_posibles();
        cout << "\nIngrese fila y columna de forma consecutiva (de esta forma: A1): ";
        cin >> ingresado;
        if (ingresado.length() == 2){
            if(isupper(ingresado[0])){
                if(isdigit(ingresado[1])){
                    if (57>=ingresado[1] && ingresado[1]>48){
                        if('A' <= ingresado[0] && ingresado[0] < ('A' + N-1)){
                            fila = ingresado[0] - 'A';
                            columna = ingresado[1] - 49;
                            for (int i = 0; i < tamaño; i += 2){
                                if (movimientos_posibles[i] == fila){
                                    if(movimientos_posibles[i + 1] == columna){
                                        validacion = true;
                                        }
                                    }
                                else continue;
                            }
                            if (validacion != true)  {
                                    system("cls");
                                    cout << "\nLa fila no coincide con ninguna columna de las opciones\n";
                            }
                        }
                        else{
                            system("cls");
                            cout << "\nAsegurese de ingresar una fila de las que se encuentran en el tablero\n";
                        }
                    }
                    else{
                        system("cls");
                        cout << "\nColumna fuera de rango\n";
                    }
                }
                else{
                    system("cls");
                    cout << "\nAsegurese de ingresar la columna como un número\n";
                }

            }
            else{
                system("cls");
                cout << "\nAsegurese de ingresar la fila en mayuscula\n";
            }

        }
        else{
            system("cls");
            cout << "\nCantidad incorrecta de caracteres.\n";
        }
    }

}

void tablero::hacer_movimiento(int fila, int columna){

}

void tablero::contar_fichas(){

}

bool tablero::terminacion(){


    return false;
}

tablero::~tablero(){
    delete [] movimientos_posibles;
    for (int i = 0; i < N ; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
