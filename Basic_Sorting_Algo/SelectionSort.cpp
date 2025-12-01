#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int arr[]={3,4,2,3,6,3,2,1,5,2,5,23,52};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n-1;i++){
        int smallPos=i;
        for(int j=i+1;j<n;j++){
            if(arr[smallPos]>arr[j]){
                  smallPos=j;
            }
        }
        swap(arr[i],arr[smallPos]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}