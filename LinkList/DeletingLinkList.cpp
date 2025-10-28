
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
     ~Node(){
        cout<<"~Node"<<" "<<data<<endl;
        if(next!=NULL){
            delete next;// next also a Node Pointer in called Node constructor until next==NULL
            next=NULL;
        }
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
  ~List(){
    cout<<"~List"<<endl;;
     if(head!=NULL){
        delete head;// head is a Node Pointer
        head=NULL;
     }
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
  void printList(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;// update temp
    }
    cout<<"NULL"<<endl;;
  }
};
int main()
{   
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    //ll.printList();//output:1->2->3->NULL
    ll.push_back(4);
    ll.push_back(5);
   // ll.printList();
    // output 1->2->3->4->5->null;
    return 0;
}