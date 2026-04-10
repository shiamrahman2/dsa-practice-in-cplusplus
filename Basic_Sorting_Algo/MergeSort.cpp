#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int st,int mid,int end){
    vector<int>temp;
    int i=st;int j=mid+1;
    while(i<=mid && j<=end){
        if(v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
     temp.push_back(v[i]);
     i++;
    }
    while(j<=end){
        temp.push_back(v[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        v[i+st]=temp[i];
    }
}
void mergeSort(vector<int>&v,int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergeSort(v,st,mid);
        mergeSort(v,mid+1,end);
        merge(v,st,mid,end);
    }
}
int main()
{   
    vector<int>arr={12,31,35,8,32,17};
    mergeSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
