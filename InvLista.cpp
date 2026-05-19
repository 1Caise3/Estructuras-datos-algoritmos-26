#include <iostream>

using namespace std;

void invertirLista(int arr[], int tam) {
    int inicio = 0;
    int fin = tam - 1;
    while (inicio < fin) {
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        inicio++;
        fin--;
    }
}

int main() {
    int lista[] = {10, 20, 30, 40, 50};
    int n = sizeof(lista) / sizeof(lista[0]);

    invertirLista(lista, n);

    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}