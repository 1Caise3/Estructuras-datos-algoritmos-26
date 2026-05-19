#include <iostream>
#include <string>

using namespace std;

class Pila {
private:
    int datos[100];
    int tope;

public:
    Pila() { tope = -1; }

    void push(int valor) {
        datos[++tope] = valor;
    }

    int pop() {
        return datos[tope--];
    }
};

int evaluarPostfija(string expr) {
    Pila pila;
    for (char c : expr) {
        if (isdigit(c)) {
            pila.push(c - '0');
        } else {
            int val2 = pila.pop();
            int val1 = pila.pop();
            switch (c) {
                case '+': pila.push(val1 + val2); break;
                case '-': pila.push(val1 - val2); break;
                case '*': pila.push(val1 * val2); break;
                case '/': pila.push(val1 / val2); break;
            }
        }
    }
    return pila.pop();
}

int main() {
    string expresion = "234*+";
    cout << evaluarPostfija(expresion) << endl;
    return 0;
}