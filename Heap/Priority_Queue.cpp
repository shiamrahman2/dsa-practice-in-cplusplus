#include<bits/stdc++.h>
using namespace std;
int main()
{   
    // max heap

    priority_queue<int>pq;
    pq.push(5);
    pq.push(10);
    pq.push(1);
    cout<<"Max heap "<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    // min heap

    priority_queue<string,vector<string>,greater<string>>p;
    p.push("Apna College");
    p.push("Shiam Hosen");
    p.push("Java");
    p.push("Python");
    cout<<"Min Heap"<<endl;
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;
}