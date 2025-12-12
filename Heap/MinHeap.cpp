#include<bits/stdc++.h>
using namespace std;
class Heap{
   vector<int>vec;
   public:
       void push(int data){// TC->O(logN)
             
        // step-1 :insert at last
        vec.push_back(data);
        // step-2 fixed CBT
        int childIdx=vec.size()-1;
        int parentIdx=(childIdx-1)/2;
        while(parentIdx>=0 && vec[childIdx]<vec[parentIdx]){// TC O(logN)
            swap(vec[childIdx],vec[parentIdx]);
            childIdx=parentIdx;
            parentIdx=(childIdx-1)/2;
        }
       }
       void heapify(int i){
        if(i>=vec.size()){
            return;
        }
        int maxIdx=i;
         int leftIdx=(2*i+1);
         int rightIdx=2*i+2;
         if(leftIdx<vec.size() && vec[leftIdx]<vec[maxIdx]){
             maxIdx=leftIdx;
         }
         if(rightIdx<vec.size() && vec[rightIdx]<vec[maxIdx]){
            maxIdx=rightIdx;
         }
         swap(vec[i],vec[maxIdx]);
         if(maxIdx!=i){
            heapify(maxIdx);
         }
       }
       void pop(){
           // step-1 swap with root to last element
           swap(vec[0],vec[vec.size()-1]);
           // step-2 : delete last node
           vec.pop_back();
           // step-3 fixed heap
           heapify(0);
       }
       int top(){
             return vec[0];
       }
       bool empty(){
           return vec.size()==0;
       }  
};
int main()
{   
    Heap heap;
    heap.push(39);
    heap.push(10);
    heap.push(100);
    heap.push(1);
  while(!heap.empty()){
    cout<<heap.top()<<endl;
     heap.pop();
  }
    return 0;
}