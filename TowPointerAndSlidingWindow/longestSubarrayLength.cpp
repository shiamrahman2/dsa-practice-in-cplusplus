#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    //brute force O(N)
    int mxLength=0;
    for(int i=0;i<n;i++){
        int sum=v[i];
        for(int j=i+1;j<n;j++){
           sum+=v[j];
           if(sum<=k){
             mxLength=max(mxLength,j-i+1);
           }else if(sum>k){
            break;
           }
        }
    }
    cout<<mxLength<<endl;
    // better TC->O(N+N)
    mxLength=0;
    int sum=0;
    int l=0,r=0;
    while(r<n){
         sum+=v[r];
        if(sum<=k){
            mxLength=max(mxLength,r-l+1);
        }
        if(sum>k){
            while(sum<=k){
                sum-+v[l];
                l--;
            }
        }
        r++;
    }
    cout<<mxLength<<endl;
    // optimal 
     mxLength=0;
     sum=0;
     l=0,r=0;
    while(r<n){
         sum+=v[r];
        if(sum<=k){
            mxLength=max(mxLength,r-l+1);
        }
        if(sum>k){
                sum-+v[l];
                l--;
        }
        r++;
    }
    cout<<mxLength<<endl;
    return 0;
}