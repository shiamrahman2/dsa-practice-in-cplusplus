#include<bits/stdc++.h>
using namespace std;
string reverseString(string str){// time and space complexity O(N);
    string ans;
    stack<char>s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{   
    string s="Shiam Hosen Monna";
    cout<<s<<endl;
    cout<<"reverse :"<<reverseString(s)<<endl;
    return 0;
}