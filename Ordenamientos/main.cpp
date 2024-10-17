#include <iostream>
#include <vector>
#include <windows.h>
//(La verdad me apoye mucho con inteligencia artificial, ultimamente no entiendo mucho de las clases salvo cuando
//explico sin el proyector  todo en el pizarron ya que iba mas lento y explicaba mejor.

//AQUI DE DONDE ES LA LIBRERIA VECTOR
// https://learn.microsoft.com/es-es/cpp/standard-library/vector-class?view=msvc-170
using namespace std;

void intercambioDirecto(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (A[i] < A[j]) {
                swap(A[i], A[j]);
            }
        }
    }
}

void insercion(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

void seleccionDirecta(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n-1; ++i) {
        int max_idx = i;
        for (int j = i+1; j < n; ++j) {
            if (A[j] > A[max_idx]) {
                max_idx = j;
            }
        }
        swap(A[i], A[max_idx]);
    }
}

int partition(vector<int>& A, int low, int high) {
    int pivot = A[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (A[j] >= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return (i + 1);
}

void quickSort(vector<int>& A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

void merge(vector<int>& A, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = A[l + i];
    for (int i = 0; i < n2; ++i) R[i] = A[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& A, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

void imprimirArray(const vector<int>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        cout << "[" << A[i] << "] ";
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Ingrese los elementos del array: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int opcion;
    char UwU = 'n';

    while (UwU != 's') {
        cout << "Seleccione el método de ordenamiento:" << endl;
        cout << "1. Intercambio Directo" << endl;
        cout << "2. Ordenamiento por Inserción" << endl;
        cout << "3. Selección Directa" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                intercambioDirecto(A);
                break;
            case 2:
                insercion(A);
                break;
            case 3:
                seleccionDirecta(A);
                break;
            case 4:
                quickSort(A, 0, A.size() - 1);
                break;
            case 5:
                mergeSort(A, 0, A.size() - 1);
                break;
            case 6:
                UwU = 's';
                continue;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << "Array ordenado: ";
        imprimirArray(A);
    }

    return 0;
}
