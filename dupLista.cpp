#include <iostream>

using namespace std;

int eliminarDuplicados(int arr[], int tam) {
    if (tam == 0 || tam == 1) return tam;

    int j = 0;
    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[tam - 1];
    return j;
}

int main() {
    int lista[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(lista) / sizeof(lista[0]);

    n = eliminarDuplicados(lista, n);

    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}