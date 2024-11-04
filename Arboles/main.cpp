#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>


using namespace std;

struct Nodo{
    int Valor;
    Nodo * Izq;
    Nodo * Der;
    Nodo * Padre;
};
//prototipos
void menu();
Nodo *CrearNodo(int, Nodo*);
void insertarNodo(Nodo *&, int, Nodo*);
void MostrarArbol(Nodo*, int);
bool BusquedaArbol(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
////---------------------------
void Eliminar(Nodo *, int);
void EliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
Nodo *maximo(Nodo *);
void remplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);
//----------------
Nodo *arbol=NULL;

int main() {
    menu();
    return 0;
}

void menu(){
    int dato, opcion, contador=0;
    do{
        cout<< "\n\t .:| Menu |:. "<<endl;
        cout<< "1. Insertar un nuevo nodo"<<endl;
        cout<< "2. Mostrar arbol"<<endl;
        cout<< "3. Buscar un elemento en el arbol"<<endl;
        cout<< "4. Recorrido en PreOrden"<<endl;
        cout<< "5. Recorrido en InOrden"<<endl;
        cout<< "6. Recorrido en PostOrden"<<endl;
        cout<< "7. Eliminar un nodo"<<endl;
        cout<< "8. Salir"<<endl;
        cout<< "\n\t Opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: 
                cout<< "Digite un numero: ";
                cin>>dato;
                insertarNodo(arbol, dato, NULL);
                cout<< "Nodo insertado correctamente"<<endl;
                sleep(1);
                break;
            case 2:
                cout<< "\n Mostrando el arbol completo."<<endl;
                    MostrarArbol(arbol, contador);
                    sleep(2);
                break;
            case 3:
                cout<< "Digite el elemento a buscar: ";
                cin>>dato;
                if(BusquedaArbol(arbol, dato)== true){
                    cout<< "Elemento "<<dato<< " ha sido encontrado en el arbol"<<endl;
                }else{
                    cout<< "Elemento "<<dato<< " no ha sido encontrado en el arbol"<<endl;
                }
                break;
            case 4:
                cout<< "Recorrido en PreOrden: ";
                preOrden(arbol);
                cout<<endl;
                break;
            case 5:
                cout<< "Recorrido en InOrden: ";
                inOrden(arbol);
                cout<<endl;
                break;
            case 6:
                cout<< "Recorrido en PostOrden: ";
                postOrden(arbol);
                cout<<endl;
                break;
            case 7:
                cout<< "Digite el nodo a eliminar: ";
                cin>>dato;
                if(BusquedaArbol(arbol, dato)== true){
                    Eliminar(arbol, dato);
                    cout<< "Nodo eliminado correctamente"<<endl;
                }else{
                    cout<< "Nodo no encontrado"<<endl;
                }
                break;
            case 8:
                cout<< "Saliendo del programa";
                    cout<< ".";
                    sleep(0.5);
                    cout<< ".";
                    sleep(0.5);
                    cout<< ".";
                    
                break;
        }
        sleep(3);
        system("clear");
    }while(opcion != 8);
    return ;
}

// Funcion para crear un nuevo nodo
Nodo * CrearNodo(int val, Nodo *padre){
    Nodo *nuevo_Nodo=new Nodo();
    nuevo_Nodo->Valor=val;
    nuevo_Nodo->Izq=NULL;
    nuevo_Nodo->Der=NULL;
    nuevo_Nodo->Padre=padre;

    return nuevo_Nodo;
}
// Funcion para intertar el nodo a arbol creado con la funcion CrearNodo
void insertarNodo(Nodo *& arbol,int val, Nodo * padre){
    if(arbol == NULL){//Si arbol esta vacio
        Nodo *nuevo_Nodo=CrearNodo(val, padre);
        arbol=nuevo_Nodo;
    }else{// si arbol esta ocupado
        int ValorRaiz= arbol->Valor;
        if(val < ValorRaiz){
            insertarNodo(arbol->Izq, val, arbol);
        }else{
            insertarNodo(arbol->Der, val, arbol);
        }
}
}
// Funcion para mostrar el arbol
void MostrarArbol(Nodo * arbol, int cont){
    int i;
    if(arbol == NULL){
        return;
    }else{
        MostrarArbol(arbol->Der, cont+1);
        for(i=0; i<cont; i++){
            cout<<" | | "; 
        }
        cout<< arbol->Valor <<endl; 
        MostrarArbol(arbol->Izq, cont +1);
    }
}
// Funcion para buscar un nodo en el arbol
bool BusquedaArbol(Nodo* arbol, int n){
    if(arbol == NULL){
        return false;
    }else if(arbol->Valor==n){
        return true;
    }else if(arbol->Valor > n){
        return BusquedaArbol(arbol->Izq, n);
    }else if(arbol -> Valor < n){
        return BusquedaArbol(arbol->Der, n);
    }
}
void preOrden(Nodo* arbol){
    if(arbol == NULL){
        return;
    }else if(arbol != NULL){
        cout<< arbol->Valor<< " -> ";
        preOrden(arbol->Izq);
        preOrden(arbol->Der);
    }
}

void inOrden(Nodo*arbol){
    if(arbol == NULL){
        return;
    }else if(arbol != NULL){
        inOrden(arbol->Izq);
        cout<< arbol->Valor<< " -> ";
        inOrden(arbol->Der);
    }
}
void postOrden(Nodo*arbol){
    if(arbol ==NULL){
        return;
    }else if(arbol != NULL){
        postOrden( arbol->Izq);
        postOrden(arbol->Der);
        cout<< arbol->Valor<< " -> ";
    }
}
void Eliminar(Nodo * arbol, int n){
    if(arbol== NULL){
        return;
    }else if(n< arbol -> Valor){
        //Buscar en el subarbol izquierdo el valor a eliminar
        Eliminar(arbol -> Izq, n);
    }else if(n> arbol->Valor){
        //Buscar en el subarbol derecho el valor a eliminar
        Eliminar(arbol-> Der, n);
    }else if(arbol-> Valor == n){
        // Eliminar el Noodo encontrado
        EliminarNodo(arbol);
    } 
}

// Funcion para eliminar el nodo encontrado
void EliminarNodo(Nodo * nodoEliminar){
    if(nodoEliminar -> Izq && nodoEliminar-> Der){
        Nodo* menor = minimo(nodoEliminar->Der);
        nodoEliminar->Valor= menor->Valor;
        EliminarNodo(menor);
    }else if(nodoEliminar -> Izq){//Tiene hijos izquierdos
        remplazar(nodoEliminar, nodoEliminar-> Izq);
        destruirNodo(nodoEliminar);
    }else if(nodoEliminar -> Der){//Tiene hijos derechos
        remplazar(nodoEliminar, nodoEliminar-> Der);
        destruirNodo(nodoEliminar);
    }else{ //No tiene hijos o es una hoja
        remplazar(nodoEliminar, NULL);
        delete nodoEliminar;

    }
}

// Funcion paa encontrar el valor mas pequeño del arbol
Nodo *minimo(Nodo * arbol){
    if(arbol==NULL){
        return NULL;
    }else if(arbol->Izq){
        return minimo(arbol->Izq);
    }else{
        return arbol;
    }
}
// Funcion para encontrar el valor mas grande del arbol
Nodo *maximo(Nodo *arbol){
    if(arbol== NULL){
        return NULL;
    }else if(arbol-> Der){
        return maximo(arbol-> Der);
    }else{
        return arbol;
    }
}

// Funcion para remplazar el nodo eliminado
void remplazar(Nodo * arbol, Nodo * remplazo){
    if(arbol-> Padre){
        // Asignaremos arbol al padre del remplazo
        if(arbol-> Valor== arbol-> Padre-> Izq -> Valor){
            arbol-> Padre-> Izq = remplazo;
        }else if(arbol-> Valor == arbol-> Padre-> Der-> Valor){
            arbol-> Padre -> Der = remplazo;
        }
    }
    //Asignar el Padre de reemplazo
    if(remplazo){
        remplazo-> Padre= arbol-> Padre;
    }
}

//Funcion para desttruir los nodos eliminados
void destruirNodo(Nodo * nodo){
    nodo->Izq;
    nodo->Der;
    delete nodo;
}