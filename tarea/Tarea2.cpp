#include <iostream>
#include <cstdlib>
//#include <windows.h>
using namespace std;

//   void SetConsoleColor(int textColor, int bgColor) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
//}
//void SetUTF8Encoding() {
//    SetConsoleOutputCP(CP_UTF8);
//    std::setlocale(LC_ALL, ".UTF-8");
//}


struct nodo {
    int valor;
    struct nodo *prox;
    //struct nodo *Puntero;
};
typedef struct nodo *Puntero;

class Cola {
    public:
        Cola(void);
        void Agregar(int);
        int Quitar(void);
        bool ColaVacia(void);
        void Mostrar(void);
        void MostrarCima(void);
        void VaciarCola(void);
        void Push(int x);
        int Pop(void);

    private:
        Puntero delante;
        Puntero atras;
};
Cola::Cola(){
    delante = NULL;
    atras = NULL;
}
void Cola::Push(int x) {
    Puntero aux= new nodo;
    aux->valor = x;
    aux->prox = delante;
    delante = aux;
    if(atras==NULL){
        atras = aux;
    }
}
int Cola::Pop(void) {
    if(ColaVacia()) {
        cout << "La estructura esta vacia, no se puede quitar elementos!!!" << endl;
        return -1;
    }
    Puntero aux = delante;
    int aux2 = aux->valor;
    delante = delante->prox;
    delete aux;
    if(delante==NULL) {
        atras = NULL;
    }
    return aux2;
}

bool Cola::ColaVacia(void) {
    if (delante== NULL) {
        return true;
    }else {
        return false;
    }
}

void Cola::Agregar( int x) {
    Puntero aux;

    aux=new nodo;
    aux->valor=x;
    aux->prox=NULL;

    if(delante==NULL) {
        delante=aux;
    }else {
        atras->prox=aux;
    }
    atras=aux;
}

int Cola::Quitar(void) {
    if (ColaVacia()) {
        cout << "La cola está vacía, no se puede quitar." << endl;
        return -1; // O algún valor que indique error
    }
    int n;
    Puntero aux = delante;
    n = aux->valor;
    delante = delante->prox;
    delete aux;
    if (delante == NULL) {
        atras = NULL; // Actualizar el puntero atras si la cola está vacía
    }
    return n;
}

void Cola::Mostrar(void) {
    if (ColaVacia()) {
        cout << "La cola está vacía." << endl;
        return;
    }
    Puntero aux = delante;
    while (aux != NULL) {
        cout << "\n\n\t" << aux->valor;
        aux = aux->prox;
    }
    cout << "\n\tFin de la cola." << endl;
}
void Cola::MostrarCima() {
    if (ColaVacia()) {
        cout<<"\n\t No hay contenido"<<endl;
    }
    cout<<"\n\tEl Valor de la cima es: "<< (delante->valor) <<endl;
}


void Cola::VaciarCola(void) {
    Puntero aux, raux;
    aux = delante;
    while (aux != NULL) {
        raux = aux;
        aux = aux->prox;
        delete raux;
    }
    delante = NULL;
    atras = NULL;
}


void menu(void) {
    cout << "\t|--------------------------------|" << endl;
    cout << "\t| IMPLEMENTACION DE UNA COLA" << endl;
    cout << "\t|--------------------------------|" << endl;
    cout << "\t| 1. Agregar \U0001F4E5" << endl; // 📥
    cout << "\t| 2. Push (Pila) \U0001F4E4" << endl; // 📤
    cout << "\t| 3. Quitar (Cola) \U0001F5D1" << endl; // 🗑️
    cout << "\t| 4. Pop (Pila) \U0001F5D1" << endl; // 🗑️
    cout << "\t| 5. Mostrar Contenido \U0001F4CB" << endl; // 📋
    cout << "\t| 6. Mostrar Cima \U0001F51D" << endl; // 🔝
    cout << "\t| 7. Vaciar Contenido \U0001F9F9" << endl; // 🧹
    cout << "\t| 8. Salir \U0001F6AA" << endl; // 🚪
    cout << "\t|--------------------------------|" << endl;
}


int main() {
//    SetConsoleColor(11, 7);
//    SetUTF8Encoding();
    Cola cola;
    int x;
    int op=-1;


    do {
        op=-1;
        system("pause");
        menu();
        cout<<endl<<"Opcion-> ";
        cin>>op;
        cout << "\n\t Opcion seleccionada: " << op << endl;
        switch(op) {
            case 1:{
                cout<<"\n\tINGRESE NUMERO A AGREGAR ->";
                cin>>x;
                cola.Agregar(x);
                cout<<"\n\n\t Se esta agregando el numero: "<<x<<endl;
                system("cls");
                break;
            }
            case 2:{
                cout<<"\n\tINGRESE NUMERO A PUSH ->";
                cin>>x;
                cola.Push(x);
                cout<<"\n\n\t Se esta agregando el numero: "<<x<<endl;
                system("cls");
                break;
            }
            case 3:{
                if(cola.ColaVacia()==true) {
                    cout<<"\n\n\tLa cola está vacia "<<endl;
                    break;
                }else {
                    x=cola.Quitar();
                    cout<<"\n\n\t El numero-> " <<x<<" Fue quitado"<<endl<<endl;
                    break;
                }
            }
            case 4: {
                if(cola.ColaVacia()==true) {
                    cout<<"\n\n\tLa pila está vacia "<<endl;
                    break;
                }else {
                    x=cola.Pop();
                    cout<<"\n\n\t El numero-> " <<x<<" Fue quitado"<<endl<<endl;
                    break;
                }
            }
            case 5: {
                cout<<"\n\t MOSTRANDO Contenido...";
                if(cola.ColaVacia()==true){
                    cout<<"\n\n\t La cola esta vacia!!!";
                    break;
                }else {
                    cola.Mostrar();
                }
                break;
            }
            case 6: {
                cout<<"\n\t MOSTRANDO Cima...";
                if(cola.ColaVacia()==true){
                    cout<<"\n\n\t La cola esta vacia!!!";
                    break;
                }else {
                    cola.MostrarCima();
                }
                break;
            }
            case 7:{
                cout<<"\n\t Vaciando...";
                if(cola.ColaVacia()==true) {
                    cout<<"\n\n\t La cola ya esta vacia!!!";
                    break;
                }else {
                    cola.VaciarCola();
                    break;
                }
            }
            case 8: {
                cout<<"\n\tSaliendo...";
                exit(0);
            }
            default:
                cout<<"Ingrese una opción valida!!!";
                break;
        }

        cout<<endl<<endl;

        //system("cls");


    }while(op!=8);
    return 0;
}
