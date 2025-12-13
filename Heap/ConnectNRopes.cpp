#include<bits/stdc++.h>
using namespace std;
int connectRopes(vector<int>ropes){
    priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());
    int cost=0;
    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        int minimum=min1+min2;
        cost+=minimum;
        pq.push(minimum);
    }
    return cost;
}
int main()
{   
    vector<int>ropes={4,3,2,6};
    int minCost=connectRopes(ropes);
    cout<<"Min Cost="<<minCost<<endl;
    return 0;
}