#include<bits/stdc++.h>
using namespace std;
void maxOfSubArraySum(int *arr,int n){
    int maxSubArray=INT_MIN;
   for(int start=0;start<n;start++){
     for(int end=start;end<n;end++){
        int currentSum=0;
        for(int i=start;i<=end;i++){  
           currentSum+=arr[i];
        }
        cout<<currentSum<<",";
        maxSubArray=max(maxSubArray,currentSum);
     }
     cout<<endl;
   }
   cout<<"Max of Sub Array Sum:"<<maxSubArray<<endl;
}
int main()
{   
    int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);
    maxOfSubArraySum(arr,n);
    return 0;
}