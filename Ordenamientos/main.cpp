//QUICK SORT

#include <iostream>
using namespace std;
void mostrarOrden(int[100],int);
void QuickSort(int[100], int, int);

int main()
{
    int i, A[100],numero = 0;
    cout<< "Cuantos elementos desea ingresar?: ";
    cin>>numero; 
    cout<<"\n\t Ingrese los elementos: "<<endl;
    for(i=0;i<=numero;i++){
        cout<<"\n\t A["<<i<<"]: ";
        cin>>A[i];
    }
    cout<<"Elementos ingresados son: "<<endl; 
    mostrarOrden(A,numero);
    cout<<endl;
    cout<<"Ordenando...";
    QuickSort(A,0;numero-1);
    cout<<"\n\n\t Elementos ordenados: ";
    mostrarOrden(A,numero);
    
    
    return 0;
}
//Funcion OrdenamientoQuickSortt
void QuickSort(int A[100],int primero, int ultimo) {
    int central, i, j, pivote, temporal;
    central=(primero+ultimo)/2; //Son las posiciones no los valores
    //Obtener el valor del elemento central
    pivote=A[central];
    //Separar los dos segmentos
    i=primero;
    j=ultimo;
    do {
        //Separar las dos partes del Array
        while(A[i]<pivote) i++; //Elementos menores al pivote
        while(A[j]>pivote) j--;//Elementos mayores al pivote
        //Intercambiar los valores
        if(i<=j) {
            A[i]=A[j];
            A[j]=temporal;
            i++;
            j--;
        }
    }while(i>=j);

    if(primero<j){
        QuickSort(A,primero,j)
    }
    if(i<ultimo){
        QuickSort(A,i,ultimo)
    }
}

void mostrarOrden(int [100],int numero){
    int i; 
    //cout<< "\n Elementos ordenados."<< endl;
    for(i=0;i<numero;i++){
        cout<<A[i]<< endl;
    }
}