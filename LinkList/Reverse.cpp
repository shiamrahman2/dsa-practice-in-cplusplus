
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
  void printList(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;// update temp
    }
    cout<<"NULL"<<endl;;
  }
  void insert(int value,int position){
     Node* newNode=new Node(value);
     Node* temp=head;
     for(int i=0;i<position-1;i++){
         temp=temp->next;
     }
     if(temp==NULL){
        cout<<"Postion Invalid";
        return;
     }else{
        newNode->next=temp->next;
        temp->next=newNode;
     }
  }
  void pop_front(){
     Node*temp=head;
     head=head->next;
     temp->next=NULL;
     delete temp;
  }
  void pop_back(){
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;// temp indicate 2nd last Node;
    delete tail;
    tail=temp;
  }
  int helper(Node* temp,int key){
    if(temp==NULL){
        return -1;
    }
      if(temp->data==key){
        return 0;
      }
      int idx=helper(temp->next,key);
      if(idx==-1){
        return -1;
      }
      return idx+1;
  }
  int searchRec(int key){
    return helper(head,key);
  }
  void reverse(){
    Node*curr=head;
    Node*prev=NULL;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;//reverse Link;
        prev=curr;
        curr=next;
    }
    // prev indicate last Node
    head=prev;
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
     ll.insert(100,2);
     ll.printList();
     ll.reverse();
     ll.printList();
    return 0;
}