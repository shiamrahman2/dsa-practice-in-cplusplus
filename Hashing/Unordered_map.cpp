#include<bits/stdc++.h>
using namespace std;
int main()
{   
    unordered_map<string,int>um;
    um["Bangladesh"]=150;
    um["Nepal"]=35;
    um["US"]=120;
    um["UK"]=145;
    um["Pakistan"]=67;
    for(pair<string,int> ans:um){
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    um.erase("Nepal");
    if(um.count("Nepal")){
        cout<<"Nepal Exist"<<endl;
    }else{
        cout<<"Nepal doesn't Exist"<<endl;
    }
    return 0;
}