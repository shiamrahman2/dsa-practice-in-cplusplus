#include<bits/stdc++.h>
using namespace std;
int main()
{   
    set<int>s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(4);
    s.insert(7);
    cout<<s.size()<<endl;
    for(auto val:s){
        cout<<val<<" ";
    }
    cout<<endl;
    if(s.find(5)!=s.end()){
        cout<<"value exist"<<endl;
    }else{
        cout<<"value Doesn't Exist"<<endl;
    }

    return 0;
}