// maximum sum with k length subarray
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    int l=0;
    int r=k-1;
    int maxSum=sum;
    while(r<n-1){
        sum-=v[l];
        l++;
        r++;
        sum+=v[r];
        maxSum=max(maxSum,sum);
    }
    cout<<maxSum<<endl;
    return 0;
}