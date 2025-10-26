#include<bits/stdc++.h>
using namespace std;
void selectionSort(int *arr,int n){
      for(int i=0;i<n-1;i++){
        int minPos=i;
        for(int j=i+1;j<n;j++){
            if(arr[minPos]>arr[j]){
                minPos=j;
            }
        }
        swap(arr[minPos],arr[i]);
      }
}
int main()
{  
    int arr[]={10,9,4,5,2,2,4,5,3};
    int n=sizeof(arr)/sizeof(int);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}