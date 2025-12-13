#include<bits/stdc++.h>
using namespace std;
class Student{
     public:
       string name;
       int marks;
       Student(string name,int marks){
         this->name=name;
         this->marks=marks;
       }
    //    bool operator <(const Student &obj)const{// max heap based on marks
    //         return this->marks < obj.marks;
    //    }

    //    bool operator < (const Student &obj) const {// max heap based on name
    //         return this->name < obj.name;
    //    }

    //     bool operator < (const Student &obj) const {// min heap based on marks
    //         return this->marks > obj.marks;
    //    }
     bool operator < (const Student &obj) const {// min heap based on name
            return this->name > obj.name;
       }

};
int main()
{  
    priority_queue<Student>pq;
    pq.push(Student("Shiam",98));
     pq.push(Student("Belal",33)); 
    pq.push(Student("Adil",99));
    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
   
    return 0;
}