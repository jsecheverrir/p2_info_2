#include "funciones.h"

char int_a_char(int columna){
    char letra = 'A' + columna;
    return letra;
}

void guardarPartida(const string& nombreJugador1, const string& nombreJugador2, char ganador) {
    // Obtener la fecha y hora actual
    time_t tiempoActual = time(nullptr); // Tomamos el tiempo actual en segundos desde una fecha de referencia.
    struct tm tiempoInfo;  // Declaramos una estructura para almacenar información detallada de la fecha y hora.
    localtime_s(&tiempoInfo, &tiempoActual); // Descomponemos el tiempo actual en sus componentes (año, mes, día, hora, minuto, segundo).

    char fechaHora[20]; // Declaramos un arreglo de caracteres para almacenar la fecha y hora formateadas.
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", &tiempoInfo);
    // Formateamos la fecha y hora usando strftime y la almacenamos en 'fechaHora'. El formato es "YYYY-MM-DD HH:MM:SS".

    // Abrir un archivo para guardar la información de la partida
    ofstream archivoPartidas("partidas.txt", ios::app);
    if (archivoPartidas.is_open()) {
        archivoPartidas << "Fecha y hora: " << fechaHora << endl;
        archivoPartidas << "Jugador 1: " << nombreJugador1 << endl;
        archivoPartidas << "Jugador 2: " << nombreJugador2 << endl;
        archivoPartidas << "Ganador: " << ganador << endl;
        archivoPartidas << "--------------------------" << endl;
        archivoPartidas.close();
        cout << "Partida guardada exitosamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo de partidas." << endl;
    }
}

void mostrarHistorial() {
    string rutaArchivo = "./partidas.txt"; // Ruta relativa al directorio actual
    ifstream archivoPartidas(rutaArchivo);
    if (archivoPartidas.is_open()) {
        string linea;
        while (getline(archivoPartidas, linea)) {
            cout << linea << endl;
        }
        archivoPartidas.close();
    } else {
        cerr << "No se pudo abrir el archivo de partidas." << endl;
    }
}
