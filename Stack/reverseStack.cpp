#include<bits/stdc++.h>
using namespace std;
void pushAtBottom(stack<int>&s,int val){
        if(s.empty()){
            s.push(val);
            return;
        }
        int topValue=s.top();
        s.pop();
        pushAtBottom(s,val);
        s.push(topValue);
}
void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int topValue=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,topValue);
}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{   
    stack<int>s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;
}