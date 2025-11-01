#include<bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
     vector<T>vec;
   public:
      void push(T value){// O(1)
        vec.push_back(value);
      }
      void pop(){// O(1)
          if(isEmpty()){
            cout<<"Vector doesn't have any element"<<endl;
            return;
          }
        vec.pop_back();
      }
      T top(){
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
    Stack<int> s;
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