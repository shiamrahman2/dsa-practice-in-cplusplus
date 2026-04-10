#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int>&nums,int st,int end){
     int idx=st-1;
     int j=st;
     int pivotElement=nums[end];
     for(;j<end;j++){
        if(nums[j]<=pivotElement){
            idx++;
            swap(nums[idx],nums[j]);
        }
     }
     idx++;
     swap(nums[idx],nums[end]);
     return idx;
}
void QuickSort(vector<int>&nums,int st,int end){
    if(st<end){
        int pivotIdx=Partition(nums,st,end);
        QuickSort(nums,st,pivotIdx-1);// call for left half
        QuickSort(nums,pivotIdx+1,end);// call for right half
    }
}
int main()
{   
    vector<int> nums={34,67,3,4,6,34,64,57,53,47,34};
    cout<<"Unsorted :";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    QuickSort(nums,0,nums.size()-1);
    cout<<"Sorted :";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}