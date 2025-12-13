#include<bits/stdc++.h>
using namespace std;
class Row{
    public:
       int count;//soilder count in row
       int row;
       Row(int count,int row){
        this->count=count;
        this->row=row;
       }
       bool operator < (const Row &obj) const{
           if(this->count ==obj.count){
              return this->row>obj.row;
           }
           return this->count>obj.count;
       }

};
void WeakestSoilder(vector<vector<int>>vec,int K){
        vector<Row>soilder;
        for(int i=0;i<vec.size();i++){
            int row=i;
            int count=0;
            for(int j=0;j<vec[i].size() && vec[i][j]==1 ;j++){
                count++;
            }
            soilder.push_back(Row(count,row));
        }
        priority_queue<Row>pq(soilder.begin(),soilder.end());
        for(int i=0;i<K;i++){
            cout<<"Weakest->"<<pq.top().row<<endl;
            pq.pop();
        }
}
int main()
{   
    vector<vector<int>>soilder={
                                 {1,0,0,0},
                                 {1,1,1,1},
                                  {1,0,0,0},
                                   {1,0,0,0}
                                 };
        WeakestSoilder(soilder,2);
    return 0;
}