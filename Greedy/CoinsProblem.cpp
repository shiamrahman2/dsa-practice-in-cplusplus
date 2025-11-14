#include<bits/stdc++.h>
using namespace std;
int minCoins(vector<int>coins,int Value){
   int n=coins.size();
   int coin=0;
   for(int i=n-1;i>=0 && Value>0;i--){
    if(Value>=coins[i]){
        coin+=Value/coins[i];
        Value=Value%coins[i];
    }
   }
   return coin;
   
}
int main()
{   
    vector<int> coins={1,2,5,10,20,50,100,500,2000};
    int coin=minCoins(coins,590);
    cout<<"Minimum number of coins required:"<<coin;
    return 0;
}