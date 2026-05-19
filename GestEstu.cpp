#include <iostream>
#include <string>

using namespace std;

class Estudiante {
private:
    int id;
    string nombres;
    string escuela;
    double promedio;

public:
    Estudiante() : id(0), nombres(""), escuela(""), promedio(0.0) {}

    Estudiante(int _id, string _nom, string _esc, double _prom) {
        this->id = _id;
        this->nombres = _nom;
        this->escuela = _esc;
        this->promedio = _prom;
    }

    void mostrarDatos() {
        cout << id << " | " << nombres << " | " << escuela << " | " << promedio << endl;
    }
};

int main() {
    Estudiante alumnos[3];
    alumnos[0] = Estudiante(1, "Cristian Coral", "Ciberseguridad", 16.5);
    alumnos[1] = Estudiante(2, "Juan Perez", "Sistemas", 14.2);
    alumnos[2] = Estudiante(3, "Ana Gomez", "Informatica", 17.8);

    for (int i = 0; i < 3; i++) {
        alumnos[i].mostrarDatos();
    }

    return 0;
}