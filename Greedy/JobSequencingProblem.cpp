#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}
int jobSequence( vector<pair<int,int>>jobs){
    sort(jobs.begin(),jobs.end(),compare);
    int n=jobs.size();
    int profit=jobs[0].second;
    int safedeadLine=2;
    for(int i=1;i<n;i++){
        if(jobs[i].first>=safedeadLine){
            profit+=jobs[i].second;
            safedeadLine++;
        }
    }
    return profit;
}
int main()
{   
   int n=4;
   vector<pair<int,int>>jobs(n,make_pair(0,0));
   jobs[0]=make_pair(4,20);
   jobs[1]=make_pair(1,10);
   jobs[2]=make_pair(1,40);
   jobs[3]=make_pair(1,30);
   int result=jobSequence(jobs);
   cout<<"Maximum Profit WithIn DeadLine->"<<result<<endl;
    return 0;
}