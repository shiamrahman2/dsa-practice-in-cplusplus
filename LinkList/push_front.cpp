
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
      int data;
      Node* next;
     Node(int value){
        data=value;
        next=NULL;
     }
};
class List{
    Node* head;
    Node* tail;
  public:
   List(){
         head=NULL;// initially head point null value
         tail=NULL;
  }
  void push_front(int value){
      Node* newNode=new Node(value);
       if(head==NULL){
           head=tail=newNode;
       }else{
           newNode->next=head;
           head=newNode;
       }
  }
  void push_back(int value){
     Node* newNode=new Node(value);// initially Node create
     if(head==NULL){// if List Empty
         head=tail=newNode;
     }else{
        tail->next=newNode;
        tail=newNode;// update tail value
     }
  }
};
int main()
{   
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    // output 1->2->3->4->5->null;
    return 0;
}