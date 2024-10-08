#include <iostream>
using namespace std;

int main()
{
    //system("color 8d");
    float a, b, c;
    float suma, resta, mult, div;
    int opcion;

    cout<<"Ingresa el primer digito: "<<endl;
    cin>>a;
    cout<<"Ingresa el segundo digito: "<<endl;
    cin>>b;
    cout<<"Ingresa el terceiro digito: "<<endl;
    cin>>c;


    cout<<"1. Suma"<<endl;
    cout<<"2. Resta"<<endl;
    cout<<"3. Multiplicacion"<<endl;
    cout<<"4. Division"<<endl;
    cout<<"5. Salir"<<endl;


    do {
        //system("cls");
        cout<<"Ingresa una opcion"<<endl;
        cin>> opcion;
        switch (opcion) {
            case 1:
                suma = a + b + c;
            cout<<"Suma = "<<suma<<endl;
                break;
            case 2:
                resta = a - b - c;
            cout<<"Resta = "<<resta<<endl;
                break;
            case 3:
                mult = a * b * c;
            cout<<"Multiplicacion = "<<mult<<endl;
                break;
            case 4:
                div = a / b / c;
            cout<<"Division = "<<div<<endl;
                break;
            case 5:
                cout<<"Adios popo!!!"<<endl;
            break;
            default:
                cout<<"Opcion no valida!"<<endl;
            break;
        }
    }while(opcion != 5);

    cout<< "\n\n\n";
    return 0;
}