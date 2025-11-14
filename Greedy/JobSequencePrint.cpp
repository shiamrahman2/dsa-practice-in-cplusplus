#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
       int idx;
       int deadline;
       int profit;
       Job(int idx,int deadline,int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
       }
};
int maxProfit(vector<pair<int,int>>jobs){
    int n=jobs.size();
    vector<Job> job;
    for(int i=0;i<n;i++){
        job.emplace_back(i,jobs[i].first,jobs[i].second);
    }
    sort(job.begin(),job.end(),[](Job &a,Job &b){
            return a.profit>b.profit;
    });
    cout<<"Selectin Job idx->"<<job[0].idx<<"--->("<<job[0].deadline<<","<<job[0].profit<<")"<<endl;
    int profit=job[0].profit;
    int safeDeadline=2;
    for(int i=2;i<n;i++){
        if(job[i].deadline>=safeDeadline){
             cout<<"Selectin Job idx->"<<job[i].idx<<"--->("<<job[i].deadline<<","<<job[i].profit<<")"<<endl;
             profit+=job[i].profit;
             safeDeadline++;
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
   int TotalProfit=maxProfit(jobs);
   cout<<"Total Maximum profit->"<<TotalProfit<<endl;
    return 0;
}