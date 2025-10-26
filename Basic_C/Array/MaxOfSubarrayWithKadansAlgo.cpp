#include<bits/stdc++.h>
using namespace std;
void maxOfSubArraySum(int *arr,int n){
    int maxSum=INT_MIN;
    int currentSum=0;
    for(int start=0;start<n;start++){
        currentSum+=arr[start];
        maxSum=max(maxSum,currentSum);
        if(currentSum<0){
            currentSum=0;
        }
    }
    cout<<"Maximum of subarray Sum:"<<maxSum<<endl;
}
int main()
{   
      int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);
    maxOfSubArraySum(arr,n);
    return 0;
}