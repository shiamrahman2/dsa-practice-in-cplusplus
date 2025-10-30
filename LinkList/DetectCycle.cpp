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
        if(next!=NULL){
            delete next;
            next=NULL;
        }
     }
};
class List{
    public:
      Node*head;
      Node*tail;
      List(){
        head=NULL;
        tail=NULL;
      }
      ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
      }
      void push_front(int value){//O(1)
         Node* newNode=new Node(value);
          if(head==NULL){
              head=tail=newNode;
          }else{
            newNode->next=head;
            head=newNode;
          }
      } 
      void push_back(int value){// O(1)
         Node* newNode=new Node(value);
         if(head==NULL){
            head=tail=newNode;
         }else{
             tail->next=newNode;
             tail=newNode;
         }
      }
      void pop_front(){// O(1)
            if(head==NULL){
                cout<<"Empty List"<<endl;
            }else{
                Node*temp=head;
                head=head->next;
                temp->next=NULL;
                delete temp;
            }
      }
      void pop_back(){// O(N);
            Node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
      }
      void insert(int value,int position){
        Node* newNode=new Node(value);
        Node* temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Position Invalid"<<endl;
        }else{
        newNode->next=temp->next;
        temp->next=newNode;
        }
      }
      void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
      }
      void reverse(){
        tail=head;
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
             Node*next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
        }
        head=prev;
      }
      int size(){
        Node*temp=head;
        int sz=0;
        while(temp!=NULL){
            sz++;
            temp=temp->next;
        }
        return sz;
      }
      int searchItr(int key){
         Node *temp=head;
         int index=0;
         while(temp!=NULL){
             if(temp->data==key){
                return index;
             }
             index++;
             temp=temp->next;
         }
         return  -1;
      }
      int helper(Node* temp,int key){
              if(temp==NULL){
                return -1;
              }
             if(temp->data==key){
                return 0;
             }
            int ind=helper(temp->next,key);
            if(ind==-1){
                return -1;
            }else{
                return ind+1;
            }
      }
      int searchRec(int key){
          return helper(head,key);
      }
      bool isCycle(){
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"Cycle Detected"<<endl;
                return true;
            }
        }
        cout<<"Don't have a cycle"<<endl;
        return false;
      }
};
int main()
{  
     List ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(0);
    ll.push_front(-1);
    ll.printList();
    cout<<ll.isCycle()<<endl;;
     ll.reverse();
    ll.printList();
     ll.reverse();
    ll.printList();
    ll.pop_front();
    ll.printList();
    ll.pop_back();
    ll.printList();
    cout<< ll.searchRec(3)<<endl;
    ll.tail->next=ll.head;
    cout<<ll.isCycle()<<endl;
    return 0;
}