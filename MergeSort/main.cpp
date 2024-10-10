#include <iostream> 
using namespace std;

void merge(int A[],int left,int mid, int right){

    int i,j,k;
    int n1=mid-left;
    int n2=right-mid;
    int L[n1],R[n2];

    for(i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(j=0;j<n2;j++){
        R[i]=A[mid+1+j];
    }
    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2){
        if(L[i]<= R[j]){
            A[k]= L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
        k++;

    }
    while(i<n1){
            A[k]= L[i];
            i++;
            k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }

}

void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid= left+(right-left)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,right);
    }
}

void mostrar(int A[],int size){
    for(int i=0;i<size;i++){
        cout<<A[i]<<"  ";  
    }
    cout<<endl; 
}

int main(){
    int Array[]={26,234,43,3,45,67,76,5,28367,266354,1};
    int sizee= sizeof(Array)/sizeof(Array[0]);
    cout<< "\n\t Lista Original "<<endl;
    mostrar(Array,sizee);
    mergeSort(Array,0,sizee-1);
    cout<<"\n Lista ordenada: ";
    mostrar(Array,sizee); 

    return 0;
}