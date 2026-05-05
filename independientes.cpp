#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

void actividad(string persona, string accion, int tiempo) {
    cout << persona << " inicia: " << accion << endl;
    this_thread::sleep_for(chrono::seconds(tiempo));
    cout << persona << " finaliza: " << accion << endl;
}

int main() {
    cout << "---- Modelo Hilos Independientes ----" << endl;
    cout << "Situacion: actividades separadas\n" << endl;

    thread h1(actividad, "Ana", "leer un libro", 3);
    thread h2(actividad, "Pedro", "hacer ejercicio", 2);
    thread h3(actividad, "Lucia", "ver una pelicula", 1);

    h1.join();
    h2.join();
    h3.join();

    cout << "\nTodas las actividades concluyeron" << endl;

    return 0;
}
