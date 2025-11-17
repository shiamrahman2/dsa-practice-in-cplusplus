#include<bits/stdc++.h>
using namespace std;
int main()
{   
    map<int,string>m;
    m[51]="Shiam";
    m[52]="Tushar";
    m[53]="Nusrat";
    m[54]="Parvez";
    for(auto it:m){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}