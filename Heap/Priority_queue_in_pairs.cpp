#include<bits/stdc++.h>
using namespace std;
struct Priority_queue_in_pairs
{
    bool operator ()( const pair<string,int>&p1, const pair<string,int>&p2){
        return p1.second<p2.second;
    }
};

int main()
{   
    priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            Priority_queue_in_pairs
    >pq;
    pq.push(make_pair("shiam",45));
    pq.push(make_pair("adil",95));
    pq.push(make_pair("rana",35));
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
        cout<<endl;
    }
    return 0;
}