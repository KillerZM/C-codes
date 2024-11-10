#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList; //Definicion de lista de adyacencia.

// Función para limpiar consola en todos los sistemas operativos
void clear(int timeY){
    #ifdef _WIN32 || _WIN64
    this_thread::sleep_for(chrono::seconds(timeY));
    system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
    this_thread::sleep_for(chrono::seconds(timeY));
    system("clear");
    #endif
}

// Crear lista de adyacencia con los nodos indicados
void CrearLista(int n){
    for(int i=0; i<n+1; i++){
        vector<int> nodo = {};
        adjList.push_back(nodo);
    }
}

// Función para agregar nodos dinámicamente
void agregarNodo(){
    vector<int> nodo{};
    adjList.push_back(nodo);
}

// Añadir enlace dirigido desde 'desde' hasta 'hacia'
void AddEnlace(int desde, int hacia){
    if(desde >= adjList.size() || hacia >= adjList.size()){
        cout<<"-> Uno o ambos nodos no existen, agrega el enlace de nuevo.\n";
        return;
    }

    // Verificar que el enlace no existe ya
    for(int i = 0; i < adjList[desde].size(); i++) {
        if(adjList[desde][i] == hacia) {
            cout << "-> El enlace ya existe.\n";
            return;
        }
    }

    adjList[desde].push_back(hacia);
}

// Eliminar enlace dirigido desde 'a' hasta 'b'
void QuitarEnlace(int a, int b){
    if(a >= adjList.size() || b >= adjList.size()){
        cout<<"-> Uno o ambos nodos no existen, intentalo de nuevo.\n";
        cout<<"-> Asegurate de que los nodos existan con opcion 'Visualizar Grafo (5)'\n";
        return;
    }
    for(int i=0; i<adjList[a].size(); i++){
        if(adjList[a][i] == b){
            adjList[a].erase(adjList[a].begin() + i);
            break;
        }
    }
}

// Imprimir la lista de adyacencia
void PrintListaAdyacencia(){
    for(int i=0; i<adjList.size(); i++){
        cout<<"Nodo "<<i<<": ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<" ["<<adjList[i][j]<<"] ";
        }
        cout<<endl;
    }
}

// Eliminar todas las conexiones del nodo NodoX
void eliminarEnlaces(int NodoX){
    for(int i =0; i<adjList.size(); i++){
        for(int j=0; j < adjList[i].size(); j++){
            if(adjList[i][j] == NodoX){
                adjList[i].erase(adjList[i].begin() + j);
                j--;  // Ajustar el índice después de la eliminación
            }
        }
    }
}

// Eliminar nodo y sus conexiones
void eliminarNodo(int NodoX){
    if(NodoX < adjList.size()){
        eliminarEnlaces(NodoX);
        adjList.erase(adjList.begin() + NodoX);

        // Ajustar los índices de los nodos restantes
        for(int i = 0; i < adjList.size(); i++){
            for(int y = 0; y < adjList[i].size(); y++){
                if(adjList[i][y] > NodoX){
                    adjList[i][y]--;            
                }
            }
        }
    } else {
        cout<<"-> El nodo no existe\n";
    }
}

// Menú para manejar el grafo
void Menu() {
    int op;
    do {
        cout << "\t--Menu--\n";
        cout << "1. Agregar nodo\n";
        cout << "2. Agregar enlace\n";
        cout << "3. Eliminar nodo\n";
        cout << "4. Eliminar enlace\n";
        cout << "5. Visualizar grafo (Lista de Adyacencia)\n";
        cout << "6. Salir\n";
        cout << "--> Ingrese una opcion: ";
        
        cin >> op;
        
        switch(op) {
            case 1:
                agregarNodo();
                break;
            case 2:
                int desde, hacia;
                cout << "--> Ingrese los nodos que desea enlazar\n Ingrese nodo Origen: ";
                cin >> desde;
                cout << "--> Ingrese Nodo destino: ";
                cin >> hacia;
                AddEnlace(desde, hacia);
                break;
            case 3:
                int NodoX;
                cout << "\n--> Ten en cuenta que ej: eliminas el nodo 1,\n el nodo 2 sera ahora el nodo 1 y asi sucesivamente\n";
                cout << "--> Ingrese el nodo que desea eliminar: ";
                cin >> NodoX;
                cout << "\n--> Eliminando nodo...\n";
                eliminarNodo(NodoX);
                break;
            case 4:
                int A, Y;
                cout << "--> Ingrese los nodos que desea desenlazar\n Ingrese nodo Origen: ";
                cin >> A;
                cout << "--> Ingrese nodo Destino: ";
                cin >> Y;
                cout << "\n--> Eliminando enlace...\n";
                QuitarEnlace(A, Y);
                break;
            case 5:
                cout << "\n--> Visualizando Lista de Adyacencia...\n";
                PrintListaAdyacencia();
                break;
            case 6: 
                cout << "--> Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
        if (op == 5 ) { clear(15); }
        else { clear(1); }
    } while (op != 6);
}

// Main
int main(){
    cout<<"\t--Grafos Dirigidos--\n";
    cout<<"Inicializacion del grafo (puede ser editado despues)\n";
    int n;
    cout<<"--> Creando grafo... (considere el nodo 0 ya esta por defecto)\n";
    cout<<"Ingrese el numero de nodos: ";
    cin >> n;
    CrearLista(n);
    int x;
    cout<<"Ingrese el numero de enlaces (aristas): ";
    cin >> x;
    while(x--){
        int desde, hacia;
        cout<<"Ingrese los nodos que desea enlazar\n Ingrese Nodo Origen: ";
        cin >> desde;
        cout<<"Ingrese Nodo destino: ";
        cin >> hacia;
        AddEnlace(desde, hacia);
    }
    Menu();
    return 0;
}
