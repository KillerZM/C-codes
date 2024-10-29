#include <iostream>
#include <string>
#include <string.h>
#include <chrono> 
#include <thread>
#define MAX 100

using namespace std;

// Estructuras para manejo de datos
struct ordenamiento {
    int elemento;
};

struct Datos {
    char Nombres[256];
    struct Datos* next;
};

typedef Datos node;
node* TablaHash[1000];
int SizeTabla = 10;

// Declaración de métodos
void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void muestra(int, struct ordenamiento[]);
int binaria(int, int, struct ordenamiento[]);
int secuencial(int, int, struct ordenamiento[]);
void MenuNum();
void MenuString();

// Métodos para hashing
int StringToKey(char name[]);
void AddNodo();
int BuscarNodo(char nameN[]);
void printTabla();

int main() {
    int n = 0, opc, keyInt, pos;
    string salir = "Saliendo";
    string keyString;
    struct ordenamiento array[MAX] = {{0}};

    cout << "-----------------------------------------------" << endl;
    cout << "-- Metodo de busqueda binaria, secuencial y hashing --" << endl;
    cout << "-----------------------------------------------" << endl;

    do {
        cout << "\nMenú principal" << endl;
        cout << "1. Ingresar un número" << endl;
        cout << "2. Ingresar una string" << endl;
        cout << "3. Buscar número (Secuencial)" << endl;
        cout << "4. Buscar número (Binaria)" << endl;
        cout << "5. Buscar string" << endl;
        cout << "6. Mostrar arreglo de números" << endl;
        cout << "7. Mostrar tabla de strings" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                if (n < MAX) {
                    cout << "Ingrese el número: ";
                    cin >> array[n].elemento;
                    n++;
                    burbuja(n, array);
                } else {
                    cout << "El arreglo está lleno." << endl;
                }
                break;
            case 2:
                AddNodo();
                break;
            case 3:
                cout << "Ingrese el número a buscar: ";
                cin >> keyInt;
                pos = secuencial(n, keyInt, array);
                if (pos != -1) {
                    cout << "Número encontrado en la posición: " << pos << endl;
                } else {
                    cout << "Número no encontrado." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el número a buscar: ";
                cin >> keyInt;
                pos = binaria(n, keyInt, array);
                if (pos != -1) {
                    cout << "Número encontrado en la posición: " << pos << endl;
                } else {
                    cout << "Número no encontrado." << endl;
                }
                break;
            case 5:
                cout << "Ingrese la string a buscar: ";
                cin >> keyString;
                pos = BuscarNodo(const_cast<char*>(keyString.c_str()));
                if (pos != -1) {
                    cout << "String encontrada con valor: " << pos << endl;
                } else {
                    cout << "String no encontrada." << endl;
                }
                break;
            case 6:
                muestra(n, array);
                break;
            case 7:
                printTabla();
                break;
            case 8:
                
                cout << (salir); 
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opc != 8);

    return 0;
}

void leerarray(int n, struct ordenamiento array[]) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> array[i].elemento;
    }
}

void burbuja(int n, struct ordenamiento array[]) {
    struct ordenamiento temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i].elemento > array[j].elemento) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void muestra(int n, struct ordenamiento array[]) {
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << array[i].elemento << " ";
    }
    cout << endl;
}

int binaria(int n, int key, struct ordenamiento array[]) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid].elemento == key) {
            return mid;
        } else if (array[mid].elemento < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int secuencial(int n, int key, struct ordenamiento array[]) {
    for (int i = 0; i < n; i++) {
        if (array[i].elemento == key) {
            return i;
        }
    }
    return -1;
}

int StringToKey(char name[]) {
    int i, c, s = 0;
    for (i = 0; i < strlen(name); i++) {
        c = name[i];
        s += c;
    }
    return s;
}

void AddNodo() {
    int ascii, form;
    node* n1;
    node* n2;
    n1 = (node*)malloc(sizeof(node));
    cout << "\n Introduzca un Nombre: ";
    cin >> n1->Nombres;
    n1->next = NULL;
    ascii = StringToKey(n1->Nombres);
    form = ascii % SizeTabla; // Transforma el ascii a llave
    cout << "\n La llave Hash es: " << "[" << form << "] " << endl;
    if (TablaHash[form] == NULL) {
        TablaHash[form] = n1;
    } else {
        n2 = TablaHash[form];
        while (n2->next != NULL) {
            n2 = n2->next;
        }
        n2->next = n1;
    }
}

int BuscarNodo(char nameN[]) {
    int ascii = StringToKey(nameN);
    int form = ascii % SizeTabla;
    node* n1;
    for (n1 = TablaHash[form]; n1 != NULL; n1 = n1->next) {
        if (strcmp(n1->Nombres, nameN) == 0) {
            cout << "El nombre " << nameN << " se encuentra en la tabla Hash" << endl;
            return form;
        }
    }
    return -1;
}

void printTabla() {
    node* n1;
    for (int i = 0; i < SizeTabla; i++) {
        cout << "[" << i << "] ";
        for (n1 = TablaHash[i]; n1 != NULL; n1 = n1->next) {
            cout << n1->Nombres << " -> ";
        }
        cout << "NULL" << endl;
    }
    cout << "\n\nFin de la tabla" << endl;
}
