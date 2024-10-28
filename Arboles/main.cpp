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
}

void menu(){}

Nodo * CrearNodo(int val, Nodo *padre){
    Nodo *nuevo_Nodo=new Nodo();
    nuevo_Nodo->Valor=val;
    nuevo_Nodo->Izq=NULL;
    nuevo_Nodo->Der=NULL;
    nuevo_Nodo->Padre=padre;

    return nuevo_Nodo;
}

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