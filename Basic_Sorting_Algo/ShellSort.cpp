#include<bits/stdc++.h>
using namespace std;
void ShellSort(vector<int>&nums,int n){
    for(int interval=n/2;interval>0;interval/=2){
        for(int j=interval;j<n;j++){
            for(int i=j-interval;i>=0;i=i-interval){
                if(nums[i+interval]>nums[i])
                   break;
                else
                   swap(nums[i+interval],nums[i]);
            }
        }
    }
}
int main()
{   
    vector<int>v={33,31,40,8,12,17,25,42};
    ShellSort(v,v.size());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}