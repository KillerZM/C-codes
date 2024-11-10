#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList; //Definicion de lista de adyacencia.
//funcion para limpiar consola en todos los sistemas operativos xd
void clear(int timeY){
    
    #ifdef _WIN32 || _WIN64
    this_thread::sleep_for(chrono::seconds(timeY));
    system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
    this_thread::sleep_for(chrono::seconds(timeY));
    system("clear");
    #endif
}


void CrearLista(int n){ //Creara una lista de adyacencia con los nodos indicados "n"
// ademas agregaremos un nodo llamado "0", que es para el mejor manejo
// de los nodos, ya que los nodos empiezan en 0, es decir si el usuario
// quiere 3 nodos, los nodos seran 0,1,2, y si el usuario quiere 4 nodos
// los nodos seran 0,1,2,3, y asi sucesivamente
    for(int i=0; i<n+1;i++){
        //Se creara un vector vacio llamado nodo
        vector<int> nodo ={};
        // EL metodo push_back agregara el vector nodo 
        //a la lista de adyacencia en su ultima posicion (como pila xd)
        //de ahi viene el "push = mandar" y "back = atras"
        adjList.push_back(nodo);
    }
}

//como el programa debe ser dinamico, ponemos la funcion de crear
//nodos y enlaces en una funcion aparte en caso
//de que el usuario quiera añadir mas nodos o enlaces
void agregarNodo(){
    vector<int> nodo{}; //Se crea un nodo vacio;
    adjList.push_back(nodo); //Se añade el nodo a la lista de adyacencia

};

void AddEnlaces(int a,int b){
    if(a >= adjList.size() || b >= adjList.size()){
        cout<<"-> Uno o ambos nodos no existen, agrega el enlace de nuevo.\n";
        return;
    }

    //esta funcion añadira los enlaces vecinos
// de los nodos de a y tambien de b (a y b son dos nodos que seran conectados)
    adjList[a].push_back(b); //Se añade el nodo b a la lista de adyacencia del nodo a
    // donde adjList[a], es un elemento de la lista de listas, en este caso
    //  adjList[a] es una lista de adyacencia del nodo a

    //Se añade el nodo a a la lista de adyacencia del nodo b
    adjList[b].push_back(a);
}

// Debido al control del usuario patata tambien debe editarse
//el enlace entre 2 nodos

void QuitarEnlace(int a,int b){
    //Primero verificaremos si los nodos existen
    if(a >= adjList.size() || b >= adjList.size()){
        cout<<"-> Uno o ambos nodos no existen, intentalo de nuevo.\n";
        cout<<"-> Asegurate de que los nodos existan con opcion 'Visuar Grafo (5)'\n";
        return;
    }
    //Esta funcion eliminara los enlaces entre los nodos a y b
    // es decir eliminara los enlaces de "a" en la lista de adyacencia de
    // "b" y viceversa
    for(int i=0; i<adjList[a].size();i++){
        //Verifica si el elemento "i" es igual a "b"
        // de ser el caso lo eliminara de la lista de adyacencia de "a"
        if(adjList[a][i]==b){
            adjList[a].erase(adjList[a].begin()+i);
            break;//este solamente se ejecutara una vez evitando
            //que se eliminen mas de un enlace.
        }
    }
    //Se eliminara el nodo "a" a la lista de adyacencia del nodo b
    for(int i=0; i<adjList[b].size();i++){
        if(adjList[b][i]==a){
            adjList[b].erase(adjList[b].begin()+i);
            break;
            //este solamente se ejecutara una vez evitando
            //que se eliminen mas de un enlace.
        }
    }
}

void PrintMatrix(){
    //Esta funcion imprimira la lista de adyacencia
    // el metodo "size()" nos da el tamaño de la lista de adyacencia
    // en este caso el tamaño de la lista de adyacencia es el numero de nodos
    // podria ser directamente "n" pero es mejor hacerlo asi en caso de
    // algun nodo que no tenga enlaces o fantasma
    for(int i=0; i<adjList.size();i++){
        cout<<"Nodo "<<i<<": ";
        //El metodo "size()" nos da el tamaño de la lista de adyacencia de un nodo
        //que en este caso es el nodo i, es decir, el nodo actual
        for(int j=0; j<adjList[i].size();j++){
            //Se imprime los nodos vecinos de i hasta que no quede ninguno
            cout<<" ["<<adjList[i][j]<<"] ";
        }
        cout<<endl;
    }
}
//Creamos la funcion que eliminara los enlaces.
void eliminarEnlaces(int NodoX){
    //Eliminaremos las conexiones del NodoX
    for(int i =0; i<adjList.size();i++){// Aqui nuevamente
    // el metodo size nos dira cuando parar
    //solo revisaremos cada lista en la lista de listas de adyacencia
        for(int j=0; j < adjList[i].size();j++){
            //Si el nodo vecino de i es igual a NodoX
            //entonces se eliminara el enlace
            if(adjList[i][j]==NodoX){

                //aqui tenemos el metodo begin()
                // que nos da el inicio de la lista de adyacencia del nodo i
                // y el metodo erase() eliminara el elemento en la posicion
                // "adjList[i].begin()+j" que es el nodo vecino de i
                // adjList[i].begin() es el inicio de la lista de adyacencia de i
                // y le sumaremos "j", que es el nodo que es identico a NodoX
                // y finalmente erase() eliminara el nodo vecino de i que es igual a NodoX
                adjList[i].erase(adjList[i].begin()+j);
            }
        }

    }
}

//Creamos la funcion de eliminacion de nodos y sus conexiones respectivas
void eliminarNodo(int NodoX){//el NodoX es el que sera eliminado
    //Eliminaremos la conexiones del NodoX
    //verificamos que NodoX existe en el grafo
    // sabemos que adjList.size() es el numero de nodos que es
    // igual a adjList.size()-1, ya que los nodos empiezan en 0
    // es decir no puede ser mayor a adjList.size()-1
    //por que ejemplo vamos 0,1,2,3 y buscamos el nodo 4
    //no existe el nodo 4, solo 0,1,2,3, aunque adjList.size() sea 4
    // debe ser adjList.size()-1 es decir menor.
    if(NodoX<adjList.size()){
        eliminarEnlaces(NodoX);//Eliminamos las conexiones de NodoX
        //Ahora debemos eliminar a NodoX de la lista Original
        // No de la lista de listas de adyacencia
        //sino de la lista de nodos
        //adjList.erase() eliminara el nodo en la posicion NodoX
        // Nuevamente adjList.begin() nos da el inicio de la lista de nodos
        // y le sumamos NodoX para eliminar el nodo en la posicion NodoX
        // es decir si vamos de 0,1,2,3 y eliminamos el nodo 2
        // adjList.begin()+2 eliminara el nodo 2
        adjList.erase(adjList.begin()+NodoX);

        //ahora arreglemos el desvalance de los nodos es decir los indices
        //de los nodos, si eliminamos el nodo 2, el nodo 3 se convierte en el nodo 2

        for(int i =0 ; i<adjList.size();i++){
            for(int y=0; y< adjList[i].size();y++){
                // ahora esto se hara solo si el nodo eliminado no 
                // el ultimo nodo, ya que si es el ultimo nodo no se hara nada
                if(adjList[i][y]> NodoX){
                    //si el nodo vecino de i es mayor a NodoX
                    //entonces se le restara 1, ya que el nodoX fue eliminado
                    //y los nodos que estan despues de NodoX se reducen en 1
                    adjList[i][y]--;            
                }
            }
        }
    }else{
        cout<<"-> El nodo no existe\n";
    }

}

//Funcion para visualizar el grafo como arbol (estas las realizo la IA)
//Ya que no se me ocurrio como hacerlo xd
void PrintTree(int nodo, int nivel, vector<bool>& visitado) {
    // Marcar el nodo como visitado
    visitado[nodo] = true;
    // Imprimir el nodo con indentación para representar el nivel
    for (int i = 0; i < nivel; ++i) {
        cout << "  ";
    }
    cout << "Nodo " << nodo << " (" << adjList[nodo].size() << " enlaces)" << endl;

    // Recoger los vecinos del nodo y ordenarlos por el número de enlaces
    vector<pair<int, int>> vecinos;
    for (int vecino : adjList[nodo]) {
        // Añadir solo los nodos que no han sido visitados
        if (!visitado[vecino]) {
            vecinos.push_back({adjList[vecino].size(), vecino});
        }
    }
    sort(vecinos.rbegin(), vecinos.rend());

    // Recorrer y imprimir los vecinos en orden decreciente de enlaces
    for (const auto& par : vecinos) {
        if (!visitado[par.second]) {
            PrintTree(par.second, nivel + 1, visitado);
        }
    }
}

void VisualizarComoArbol() {
    if (adjList.empty()) {
        cout << "El grafo está vacío." << endl;
        return;
    }

    vector<bool> visitado(adjList.size(), false); // Vector para marcar nodos visitados

    // Buscar un nodo que tenga enlaces para empezar la impresión
    int nodoInicial = -1;
    for (int i = 0; i < adjList.size(); ++i) {
        if (!adjList[i].empty()) {
            nodoInicial = i;
            break;
        }
    }

    if (nodoInicial == -1) {
        cout << "El grafo no tiene enlaces." << endl;
    } else {
        PrintTree(nodoInicial, 0, visitado); // Iniciar la impresión desde el primer nodo con enlaces
    }
}

//Funcion para visualizar el grafo como arbol (estas las realizo la IA)


//creamos el menu con las opciones de edicion y visualizacion.
void Menu() {
    int op;
    do {
        cout << "\t--Menu--\n";
        cout << "1. Agregar nodo\n";
        cout << "2. Agregar enlace\n";
        cout << "3. Eliminar nodo \n";
        cout << "4. Eliminar enlace\n";
        cout << "5. Visualizar grafo (Listas de Adyacencia)\n";
        cout << "--- Funcion experimental no tomarse en cuenta --- \n";
        cout << "6. Visualizar como arbol (solo funciona si no se borran nodos (BETA XD))\n"; // Opcion de chatgpt
        cout << "7. Salir\n"; // Actualiza el número de salida
        cout << "--> Ingrese una opcion: ";
        
        cin >> op;
        
        switch(op) {
            case 1:
                agregarNodo();
                break;
            case 2:
                int a, b;
                cout << "--> Ingrese los nodos que desea enlazar\n Ingrese a: ";
                cin >> a;
                cout << "--> Ingrese b: ";
                cin >> b;
                AddEnlaces(a, b);
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
                cout << "--> Ingrese los nodos que desea desenlazar\n Ingrese a: ";
                cin >> A;
                cout << "--> Ingrese b: ";
                cin >> Y;
                cout << "\n--> Eliminando enlace...\n";
                QuitarEnlace(A, Y);
                break;
            case 5:
                cout << "\n--> Visualizando Matriz de adyacencia...\n";
                PrintMatrix();
                break;
            case 6:
                cout << "\n--> Visualizando como arbol...\n";
                VisualizarComoArbol();
                break;
            case 7: 
                cout << "--> Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
        // Llamada a la funcion clear para limpiar la consola
        if (op == 5 || op == 6) { clear(15); }
        else { clear(2); }
    } while (op != 7); // Actualiza el número de salida
}



//Grafos no dirigidos
int main(){

    cout<<"\t--Grafos no dirigidos--\n";
    cout<<"Inicializacion del grafo (puede ser editado despues)\n";
    int n;
    cout<<"--> Creando grafo... (considere el nodo 0 ya esta por defecto)\n";
    cout<<"Ingrese el numero de nodos: ";
    cin>>n;
    //Aqui el usuario ingresara el numero de nodos que desea tener en su grafo
    CrearLista(n);
    int x; // aqui el usuario ingresa los enlaces que desea tener
    cout<<"Ingrese el numero de enlaces (aristas): ";
    cin>>x;
    //aqui se ejecuta el codigo el numero de q, hasta que q sea 0
    while(x--){
        int a,b; //Aqui se toma a y b como los nodos que queremos
        //Enlazar;
        cout<<"Ingrese los nodos que desea enlazar\n Ingrese a: ";
        cin>>a;
        cout<<"Ingrese b: ";
        cin>>b;
        AddEnlaces(a,b);
    }

    //Hasta este punto ya tenemos nuestro grafo creado
    //ahora solo falta el menu de edicion y visualizacion
    Menu();
    return 0;
}