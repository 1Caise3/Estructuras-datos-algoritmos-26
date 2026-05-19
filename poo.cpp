#include <iostream>
#include <string>
using namespace std;


class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string nom, int ed) {
        this->nombre = nom;
        this->edad = ed;
    }

    virtual void presentarse() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " anos" << endl;
    }

    virtual void realizarActividad() = 0;

    virtual ~Persona() {}
};

class Empleado : public Persona {
private:
    string departamento;
    double salario;

public:

    Empleado(string nom, int ed, string dept, double sal) : Persona(nom, ed) {
        this->departamento = dept;
        this->salario = sal;
    }

    void presentarse() override {
        Persona::presentarse();
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Mensual: S/. " << salario << endl;
    }

    void realizarActividad() override {
        cout << "El empleado " << nombre << " esta trabajando en el area de " << departamento << "." << endl;
    }
};

int main() {
    cout << "EJEMPLO DE POO EN C++" << endl << endl;

    Persona* trabajador = new Empleado("Cristian Coral", 21, "Ciberseguridad", 4500.50);

    trabajador->presentarse();
    cout << endl;
    trabajador->realizarActividad();

    delete trabajador;

    return 0;
}