#include <iostream>


#define MAX 50
using namespace std;

struct ordenamiento {
    int elemento;
};

void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void muestra(int, struct ordenamiento[]);
int binaria(int, int, struct ordenamiento[]);

int main() {
        int n, pos, z;
        struct ordenamiento array[MAX];
        cout << "-----------------------------------------------" << endl;
        cout << "-- Metodo de busqueda binaria --" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese el numero de elementos del arreglo: ";
        cin >> n;
        leerarray(n,array);
        burbuja(n,array);
        muestra(n,array);
        cout << "Ingrese el elemento a buscar: ";
        cin >> z;
        pos = binaria(n,z,array);

        if(pos == -1){
            cout << "El elemento no se encuentra en el arreglo" << endl;
            return 0;
        }else{cout << "\n\nEl elemento " << z << " se encuentra en la posicion " << pos + 1 << "\n\n\n";
        }
}

void leerarray(int n, struct ordenamiento a[]) {
    int i;
    for (i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> a[i].elemento;
    }
}

void burbuja(int n, struct ordenamiento a[]){
    int i, j;
    struct ordenamiento aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[j].elemento > a[j + 1].elemento) {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
};

void muestra(int n, struct ordenamiento a[]){
    int i;
    cout << "El arreglo ordenado es el siguiente: "<<endl ;
    cout<< "---------------------------------------"<< endl;
    for (i = 0; i < n; i++) {
        cout << a[i].elemento << " ";
    }
    cout <<endl << "---------------------------------------" << endl;
};

int binaria(int der, int iz, struct ordenamiento a[]){
    int mitad, izq,drch;
    izq=0;
    drch= der-1;
    while(izq<=drch){
        mitad=(izq+drch)/2;
        if(a[mitad].elemento==iz){
            return mitad;
        }
        if(a[mitad].elemento>iz){
            drch=mitad-1;
        }
        else{
            izq=mitad+1;
        }
    }
    return -1;
};