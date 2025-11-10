#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      int data;
      Node* next;
      Node(int val){
        this->data=val;
        next=NULL;
      }
};
class List{
   public:
      Node* head;
      List(){
        head=NULL;
      }
      void push_back(int value){
         Node* newNode=new Node(value);
         if(head==NULL){
            head=newNode;
         }else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
         }
      }
      void printLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
      }
};
int main()
{   
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printLL();
    return 0;
}