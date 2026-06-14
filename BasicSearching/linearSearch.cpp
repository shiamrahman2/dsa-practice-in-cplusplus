#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main()
{   
    int arr[]={5,6,3,63,234,5234,95};
    int n=sizeof(arr)/sizeof(int);
    int index=linearSearch(arr,n,63);
    if (index==-1){
        cout<<"Element doesn't exist";
    }else{
        cout<<"Element Index-"<<index<<endl;
    }
    return 0;
}