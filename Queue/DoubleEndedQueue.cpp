#include<bits/stdc++.h>
using namespace std;
int main()
{   
    deque<int>dq;
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);
    cout<<"Front Value:"<<dq.front()<<endl;
    cout<<"Back Value:"<<dq.back()<<endl;
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}