#include "clases.h"

int main(){
    tablero prueba;
    //prueba.imprimir_tablero();
    prueba.mostrar_movimientos_posibles();
    cout << "\n";
    cout << prueba.get_capacidad();
    cout << "\n";

    prueba.push_back(4);
    prueba.push_back(5);
    prueba.mostrar_movimientos_posibles();
    cout << "\n";
    cout << "\n" << prueba.get_capacidad()<< "\n";
    prueba.push_back(4);
    prueba.push_back(5);
    prueba.mostrar_movimientos_posibles();
    cout << "\n" << prueba.get_capacidad()<< "\n";
    prueba.push_back(4);
    prueba.push_back(5);
    prueba.mostrar_movimientos_posibles();
    cout << "\n" << prueba.get_capacidad()<< "\n";
    prueba.push_back(4);
    prueba.push_back(5);
    prueba.mostrar_movimientos_posibles();
    cout << "\n" << prueba.get_capacidad()<< "\n";
    prueba.push_back(4);
    prueba.push_back(5);
    prueba.mostrar_movimientos_posibles();
    cout << "\n" << prueba.get_capacidad()<< "\n";
    return 0;
}
