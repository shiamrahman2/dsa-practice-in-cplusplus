#include<bits/stdc++.h>
using namespace std;
class Car{
   public:
      int idx;
      int disSq;
      Car(int idx,int disSq){
        this->idx=idx;
        this->disSq=disSq;
      }
      bool operator < (const Car &obj) const{
        return this->disSq>obj.disSq;// min heap
      }
};
void NearByCars(vector<pair<int,int>>pos,int K){
        vector<Car>cars;
        for(int i=0;i<pos.size();i++){
            int disSq=(pos[i].first*pos[i].first)+(pos[i].second*pos[i].second);
            cars.push_back(Car(i,disSq));
        }
        priority_queue<Car>car(cars.begin(),cars.end());// TC->O(logN)
        // similar
        // for(int i=0;i<cars.size();i++){// TC->O(N*logN) not preferable
        //     car.push(cars[i]);
        // }
        for(int i=0;i<K;i++){ //O(K * logN)
            cout<<"Car "<<car.top().idx<<endl;//TC->O(1)
            car.pop();//O( logN)
        }
}
int main()
{   
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
     pos.push_back(make_pair(5,-1));
      pos.push_back(make_pair(-2,4));
      int K=2;
      NearByCars(pos,K);
    return 0;
}