#include<bits/stdc++.h>
using namespace std;
int main()
{   
     int arr[]={3,4,2,3,6,3,2,1,5,2,5,23,52};
    int n = sizeof(arr)/sizeof(int);
    
    // Ascending Order

    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+n,greater<int>());
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}