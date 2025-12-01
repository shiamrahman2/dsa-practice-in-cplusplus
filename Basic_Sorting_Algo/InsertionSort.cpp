#include<bits/stdc++.h>
using namespace std;
void InserTionSort(int arr[],int n){
     for(int i=1;i<n;i++){
        int currValuePos=i-1;
        int currValue=arr[i];
        while(currValuePos>=0 && arr[currValuePos]>currValue){
            arr[currValuePos+1]=arr[currValuePos];
            currValuePos--;
        }
        arr[currValuePos+1]=currValue;
     }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
}
int main()
{   
    int arr[]={3,4,2,3,6,3,2,1,5,2,5,23,52};
    int n=sizeof(arr)/sizeof(int);
    InserTionSort(arr,n);
    printArr(arr,n);
    return 0;
}