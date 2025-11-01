#include<bits/stdc++.h>
using namespace std;
void maxAreaOfHistrogram(vector<int>v){
        int n=v.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        stack<int>s;
        nsl[0]=-1;
        s.push(0);
        // find left next Smallest Value
        for(int i=1;i<n;i++){
            int curr=v[i];
            while(!s.empty() && curr<=v[s.top()]){
                 s.pop();
            }
            if(s.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        // find right Smallest value;
        nsr[n-1]=n;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            int curr=v[i];
            while(!s.empty() && curr<=v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nsr[i]=n;
            }else{
                nsr[i]=s.top();
            }
           s.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int ht=v[i];
            int width=nsr[i]-nsl[i]-1;
            int area=ht*width;
            maxArea=max(maxArea,area);
        }
    cout<<"Maximum Area:"<<maxArea<<endl;


}
int main()
{   
    vector<int>vec={2,1,5,6,2,3};
     maxAreaOfHistrogram(vec);
    return 0;
}