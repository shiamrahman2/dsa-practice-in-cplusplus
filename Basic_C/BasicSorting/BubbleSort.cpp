#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr,int n){
     for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j =0;j<n-i-1;j++){
              if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
              }
        }
        if(!flag){
            break;
        }
     }
}
int main()
{   
    int arr[]={3,4,2,1,5};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}