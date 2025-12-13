#include<bits/stdc++.h>
using namespace std;
int main()
{   
    map<string,int>om;
    om["Bangladesh"]=150;
    om["Nepal"]=35;
    om["US"]=120;
   om["UK"]=145;
    om["Pakistan"]=67;
    for(pair<string,int> ans:om){
        cout<<ans.first<<" "<<ans.second<<endl;
    }
   om.erase("Nepal");
    if(om.count("Nepal")){
        cout<<"Nepal Exist"<<endl;
    }else{
        cout<<"Nepal doesn't Exist"<<endl;
    }
    return 0;
}