#include <iostream>
using namespace std;


void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];
    int i = low-1;

    for (int j = low; j <= high-1; j++)  
    {   
        if(arr[j]%2 !=0) {
          arr[j]=arr[j]-1;
        }
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    
    swap(&arr[i+1], &arr[high]);
    
    return i+1;  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
    if(arr[high]%2!=0) arr[high]-=1;
}  


int verificar(int tam,int arr[])
{
  int numeroMayor = 0;

   for(int i=0; i<=tam;i++){
     if (arr[i]%2==0)
   {

      if(numeroMayor<arr[i])
      {
        numeroMayor = arr[i];
      }
   }
  }
  
return numeroMayor+2;
}




int main() {
  
    int T, n, A=0, num;
    cin>>T;
    while(T>0){
      cin>>n;
      int arr[n];
      for(int k=0; k<n; k++){
        cin>>A;
        arr[k]=A;
      }

      quickSort(arr, 0, n-1);
      num=verificar(n,arr);
      cout<<num<<endl;

      T--;
    }



}