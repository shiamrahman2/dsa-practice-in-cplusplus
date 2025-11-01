#include<bits/stdc++.h>
using namespace std;
class Stack{
     vector<int>vec;
   public:
      void push(int value){// O(1)
        vec.push_back(value);
      }
      void pop(){// O(1)
          if(isEmpty()){
            cout<<"Vector doesn't have any element"<<endl;
            return;
          }
        vec.pop_back();
      }
      int top(){
        if(isEmpty()){
            cout<<"vector doesn't have any element"<<endl;
            return -1;
        }
        int topInd=vec.size()-1;
        return vec[topInd];
      }
      bool isEmpty(){
        if(vec.size()==0)
           return true;
        else false;
      }
};
int main()
{   
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}