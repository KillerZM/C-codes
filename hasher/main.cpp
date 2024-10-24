#include <iostream>
#include <string.h>

using namespace std;

struct Datos{
    char Nombres[256];
    struct Datos* next;
}typedef node;

node *TablaHash[1000];
int SizeTabla = 10;

int StringToKey(char name[]){
    int i,c,s=0;
    for(i=0; i< strlen(name); i++){
        c=name[i];
        s +=c;
    }
    return s;
}

void AddNodo(){
    int ascii, form;
    node *n1;
    node *n2;

    n1=(node *)malloc(sizeof(node));
    cout<< "\n Introduzca un Nombre: ";
    cin>> n1->Nombres;
    n1->next=NULL;

    ascii=StringToKey(n1->Nombres);
    form = ascii % SizeTabla;//Transforma el ascii a llave
    cout<< "\n La llave Hash es: "<< "["<< form<< "] "<<endl;

    if(TablaHash[form]==NULL){
        TablaHash[form]=n1;
    }else{
        for(n2=TablaHash[form]; n2->next!=NULL; n2=n2->next){
            n2->next=n1;
        };
    }
}

int BuscarNodo(char nameN[]){
    int ascii = StringToKey(nameN);
    int form = ascii % SizeTabla;
    node *n1;
    for(n1=TablaHash[form]; n1!=NULL; n1=n1->next){
        if(strcmp(n1->Nombres, nameN)==0){
            cout<< "El nombre "<< nameN<< " se encuentra en la tabla Hash"<<endl;
            return form;
        }
    }
    return -1;
}

void printTabla(){
    node *n1,i;
    for(int i=0; i<SizeTabla; i++){
        cout<< "["<< i<< "] ";
        for(n1=TablaHash[i]; n1!=NULL; n1=n1->next){
            cout<< n1->Nombres<< " -> ";
        }
        cout<< "NULL"<<endl;
    }
    cout<< "\n\nFin de la tabla"<<endl;
}

void Menu(){
    cout<<"\t\n---Busqueda Hashing---"; 
    cout<< "\n1.- Agregar Nombre"<<endl;
    cout<< "2.- Buscar Nombre"<<endl;
    cout<< "3.- Imprimir Tabla"<<endl;
    cout<< "4.- Salir"<<endl;
    cout<< "Opcion: ";
}

int main(){
    int opc,i;
    char name[256];
    do{
        Menu();
        cin>> opc;
        switch(opc){
            case 1:
                system("clear");
                AddNodo();
                break;
            case 2:
                system("clear");
                cout<< "\nIntroduzca el nombre a buscar: ";
                cin>> name;
                BuscarNodo(name);
                break;
            case 3:
                system("clear");
                printTabla();
                break;
            case 4:
                system("clear");
                cout<< "\nSaliendo..."<<endl;
                break;
            default:
                system("clear");
                cout<< "\nOpcion no valida"<<endl;
                break;
        }
    }while(opc!=4);
    return 0;
}