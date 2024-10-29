#include <iostream>
#define MAX 50
using namespace std;

struct ordenamiento {
    int elemento;
};

void leerarray(int, struct ordenamiento[]);
void muestra(int, struct ordenamiento[]);
int secuencial(int, int, struct ordenamiento[]);
int menu();

int main() {
    int n, pos, z, opc;
    struct ordenamiento array[MAX];
    cout << "-----------------------------------------------" << endl;
    cout << "-- Metodo de busqueda secuencial --" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingrese el numero de elementos del arreglo: ";
    cin >> n;
    leerarray(n, array);
    muestra(n, array);
    cout << "Ingrese el elemento a buscar: ";
    cin >> z;
    pos = secuencial(n, z, array);
    if (pos == -1) {
        cout << "El elemento no se encuentra en el arreglo" << endl;
    } else {
        cout << "\n\nEl elemento " << z << " se encuentra en la posicion " << pos + 1 << "\n\n\n";
    }
    return 0;
}

void leerarray(int n, struct ordenamiento a[]) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> a[i].elemento;
    }
}

void muestra(int n, struct ordenamiento a[]) {
    cout << "El arreglo es el siguiente: " << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i].elemento << " ";
    }
    cout << endl << "---------------------------------------" << endl;
}

int secuencial(int n, int x, struct ordenamiento a[]) {
    for (int i = 0; i < n; i++) {
        if (a[i].elemento == x) {
            return i;
        }
    }
    return -1;
}
