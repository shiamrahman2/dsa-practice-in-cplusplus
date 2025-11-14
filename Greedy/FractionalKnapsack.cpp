#include<bits/stdc++.h>
using namespace std;
bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
int maxFactionalKnapsack(vector<int>value,vector<int>weight,int maxWeight){
    int n=value.size();
    vector<pair<double,int>>ratio(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        double r=value[i]/(double)weight[i];
        ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int index=ratio[i].second;
        if(weight[index]<=maxWeight){
            ans+=value[index];
            maxWeight-=weight[index];
        }else{
            ans+=ratio[i].first*maxWeight;
            maxWeight=0;
            break;
        }
    }
     return ans;
}
int main()
{   
    vector<int> value={60,120,100};
    vector<int> weight={10,30,20};
    int ans=maxFactionalKnapsack(value,weight,50);
    cout<<ans<<endl;
    return 0;
}