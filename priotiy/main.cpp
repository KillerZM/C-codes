#include <iostream>
#include <stdlib>

using namespace std;
//Estructura de los nodos
struct nodo{
    char dato;
    int prio; //Prioridad del Nodo
    struct nodo *next;
};
//Estructura Cola
struct cola{
    nodo * delante;
    nodo * atras;
};
// Estructura de inserción
struct nodo *crearNodo(char Datos, int Prioridad){
    struct nodo *nuevoNodo= new (struct nodo);
    nuevoNodo->dato = Datos;
    nuevoNodo->prio = Prioridad;
    return nuevoNodo;
}

void Agregar(struct  cola&q, char Data, int Priority){
    struct nodo* aux= new crearNodo(Data, Priority);
    aux->next= NULL;
    if(q.delante== NULL){
        q.delante = aux;
    }else{
        (q.atras)->next = aux;
    }
        q.atras= aux;    
}

void Mostrar(struct cola q){
    struct nodo* aux;
    aux = q.delante;
    cout<<"\n\tCaracter prioridad."<<endl;
    cout<< "______________________"<< endl;
    while(aux !NULL){
        cout<<" "<< aux-> dato<< " | "<< aux->prio << endl;
        aux = aux-> next;
    }
}

void PrioSort(struct cola&q){
    struct nodo *aux,*aux2;
    int nAux;
    char cAux;

    aux = q.delante;
    while(aux->next !NULL){
        aux2 = aux->next;
        while(aux2 !NULL){
            if(aux1->prio > aux2->prio){
                nAux = aux1 -> prio;
                cAux = aux1 -> dato;

                aux1->prio = aux2-> prio;
                aux1->dato = aux2-> dato;

                aux2->prio = nAux;
                aux2->dato = cAux;
            }
            aux2 = aux2->next;
        }
        aux1 = aux1-> next;
    }
}

void insertar( struct cola&q,char Data, int Priority){
    agregar(q, Data, Priority);
    PrioSort(q);
}

void menu(){
    cout<<"\n\t Cola con Prioridad"<< endl;
    cout<<"\t___________________________";
    cout<<"\n\t 1. Agregar ";
    cout<<"\n\t 2. Mostrar ";
    cout<<"\n\t 3. Salir "<< endl;
    cout<<"\t Int Opcion: ";
}

int main(){
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;

    char cad;
    int pr,opc,x;

    do{
        opc=0;
        menu();
        cin>>opc;
        cout <<endl;
        switch(opc){
            case 1:
                cout<<"\n\t Ingrese el Caracter-> ";
                cin>>cad;
                cout<<"\n\t Ingrese la Prioridad-> ";
                cin>>pr;
                insertar(q,c,pr);
                cout<<"\n\t Usuario: "<< cad<< " Fue insertado";
                cout<<"\n\t Con Prioridad: "<< pr<< endl;
                break;
            case 2:
                cout<<"\n\t Mostrando cola de prioridad..."<< endl;
                if(q.delante !NULL){
                    Mostrar(q);
                }else{
                    cout<<"\n\t La cola no tiene contenido !!! 😡";
                }
                break;
            case 3:
                cout<<"\n\t Saliendo...";
                exit(0);
                
            default:{
                cout<<"\n\t Ingresa una opcion valida. [1-3]";
            }

        }
    }while(opc!3);
}