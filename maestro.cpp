#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

string trabajos[8] = {
    "Tarea 1", "Tarea 2", "Tarea 3", "Tarea 4",
    "Tarea 5", "Tarea 6", "Tarea 7", "Tarea 8"
};

int completadas[3] = {0, 0, 0};

void trabajador(int id, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        cout << "Trabajador " << id << " ejecutando: " << trabajos[i] << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Trabajador " << id << " finalizo: " << trabajos[i] << endl;
        completadas[id - 1]++;
    }
    cout << "Trabajador " << id << " termino su parte\n";
}

int main() {
    cout << "---- Modelo Maestro-Trabajador ----" << endl;
    cout << "Situacion: distribucion de tareas\n" << endl;

    thread t1(trabajador, 1, 0, 3);
    thread t2(trabajador, 2, 3, 6);
    thread t3(trabajador, 3, 6, 8);

    t1.join();
    t2.join();
    t3.join();

    cout << "\nTrabajo total completado\n";
    cout << "Trabajador 1: " << completadas[0] << endl;
    cout << "Trabajador 2: " << completadas[1] << endl;
    cout << "Trabajador 3: " << completadas[2] << endl;

    return 0;
}