#include "clases.h"

int main(){
    tablero prueba;

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


    /*
    prueba.imprimir_tablero();





    prueba.mostrar_movimientos_posibles();
    cout << "\n";
    cout << prueba.get_capacidad();
    cout << "\n";


*/


    return 0;
}
