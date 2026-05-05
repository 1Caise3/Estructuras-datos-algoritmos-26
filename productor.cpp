#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void contarPuntos(int inicio, int fin, int id, int &suma) {
    suma = 0;
    cout << "Trabajador " << id << " empezando su parte..." << endl;

    for (int i = inicio; i < fin; i++) {
        suma += 10;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "Trabajador " << id << " acabo. Sumo: " << suma << endl;
}

int main() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    cout << "=== EJEMPLO DE PARALELISMO (3 HILOS) ===\n" << endl;

    int p1 = 0, p2 = 0, p3 = 0;

    thread hilo1(contarPuntos, 0, 5, 1, ref(p1));
    thread hilo2(contarPuntos, 5, 10, 2, ref(p2));
    thread hilo3(contarPuntos, 10, 15, 3, ref(p3));

    hilo1.join();
    hilo2.join();
    hilo3.join();

    cout << "\nSuma total: " << (p1 + p2 + p3) << endl;

    return 0;
}
