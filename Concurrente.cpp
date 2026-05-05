#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void tarea(string nombre, int tiempo) {
    cout << "Iniciando tarea: " << nombre << endl;
    this_thread::sleep_for(chrono::seconds(tiempo));
    cout << "Tarea finalizada: " << nombre << endl;
}

int main() {
    limpiarPantalla();

    cout << "---- Modelo Concurrente ----" << endl;
    cout << "Situacion: multiples tareas ejecutandose al mismo tiempo\n" << endl;

    thread h1(tarea, "Descarga de archivo", 3);
    thread h2(tarea, "Procesamiento de datos", 2);
    thread h3(tarea, "Actualizacion del sistema", 1);

    h1.join();
    h2.join();
    h3.join();

    cout << "\nTodas las tareas han finalizado." << endl;

    return 0;
}
