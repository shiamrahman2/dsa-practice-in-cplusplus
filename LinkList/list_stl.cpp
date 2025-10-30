#include<bits/stdc++.h>
using namespace std;
void printList(list<int>ll){
       list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}
int main()
{   
    list<int>ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    // 1->2->3->4->NULL;
    printList(ll);
    cout<<ll.size();// return size of linked list
    cout<<"head->"<<ll.front()<<endl;
    cout<<"tail->"<<ll.back()<<endl;
    auto it=ll.begin();
    advance(it,3);
    ll.insert(it,7,9);

    printList(ll);
    return 0;
}