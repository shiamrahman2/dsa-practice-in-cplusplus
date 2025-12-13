#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&vec,int i,int n){// TC->O(N)
    int left=2*i+1;
    int right=2*i+2;
    int maxIdx=i;
    if(left<n && vec[left]>vec[maxIdx]){
        maxIdx=left;
    }
    if(right<n && vec[right]>vec[maxIdx]){
        maxIdx=right;
    }
    if(maxIdx!=i){
        swap(vec[i],vec[maxIdx]);
        heapify(vec,maxIdx,n);
    }
}
void HeapSort(vector<int>&vec){
    int n=vec.size();
    // step-01: build maxHeap
    for(int i=(n/2-1); i>=0;i--){//TC->O(N*logN)
          heapify(vec,i,n);
    }
    // step-02: correcting position for each element
    for(int i=n-1;i>=0;i--){//TC->O(N*logN)
        swap(vec[0],vec[i]);
        heapify(vec,0,i);
    }

}
int main()
{ 
    vector<int>vec={1,4,2,5,3};  
    HeapSort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}