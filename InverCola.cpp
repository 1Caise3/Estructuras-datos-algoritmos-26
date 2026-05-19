#include <iostream>

using namespace std;

class Cola {
public:
    int datos[100];
    int frente, final, tam;

    Cola() {
        frente = 0;
        final = -1;
        tam = 0;
    }

    void push(int valor) {
        datos[++final] = valor;
        tam++;
    }

    int pop() {
        int aux = datos[frente++];
        tam--;
        return aux;
    }

    bool vacia() {
        return tam == 0;
    }
};

void invertirCola(Cola &c) {
    if (c.vacia()) return;
    int elemento = c.pop();
    invertirCola(c);
    c.push(elemento);
}

int main() {
    Cola miCola;
    miCola.push(1);
    miCola.push(2);
    miCola.push(3);
    miCola.push(4);

    invertirCola(miCola);

    while (!miCola.vacia()) {
        cout << miCola.pop() << " ";
    }
    cout << endl;

    return 0;
}