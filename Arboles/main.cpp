#include <iostream>
#include <stdlib.h>
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
void MostratArbol(Nodo*, int);
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
    
    return 0;
};

void menu(){}
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
        if(val > ValorRaiz){
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
        return;
    }else if(arbol->Izq){
        return minimo(arbol->Izq);
    }else{
        return arbol;
    }
}
// Funcion para encontrar el valor mas grande del arbol
Nodo *maximo(Nodo *arbol){
    if(arbol== NULL){
        return;
    }else if(arbol-> Der){
        return maximo(arbol-> Der);
    }else{
        return arbol;
    }
}

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