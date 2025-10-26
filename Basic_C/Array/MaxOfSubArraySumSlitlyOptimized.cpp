#include<bits/stdc++.h>
using namespace std;
void maxSubArraySum(int *arr,int n){
    int maxSum=INT_MIN;
     for(int start=0;start<n;start++){
        int currentSum=0;
        for(int end=start;end<n;end++){
             currentSum+=arr[end];
             maxSum=max(maxSum,currentSum);
        }
     }
     cout<<"Maximum subarray sum:"<<maxSum<<endl;
}
int main()
{   
    int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);
    maxSubArraySum(arr,n);
    return 0;
}