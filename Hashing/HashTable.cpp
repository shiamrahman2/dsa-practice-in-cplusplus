#include<bits/stdc++.h>
using namespace std;
class Node{
      
    public:
       string key;
       int val;
       Node* next;
       Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
       }
       ~Node(){
          if(next!=NULL){
            delete next;
          }
       }

};
class HashTable{
     int totalSize;
     int currSize;
     Node** table;// pointer of pointer
     int hashFunction(string key){
          int idx=0;
          for(int i=0;i<key.size();i++){
            idx=idx+(key[i]*key[i])%totalSize;
          }
          return idx%totalSize;
     }
     void rehash(){
        Node** oldTable=table;
        int oldSize=totalSize;
        totalSize=2*oldSize;
        currSize=0;// resize currSize 
        for(int i=0;i<totalSize;i++){
            table[i]=NULL;
        }
        table=new Node*[totalSize];
        for(int i=0;i<oldSize;i++){
            Node* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
     }
    public:
       HashTable(int size=5){// using default parameter
          this->totalSize=size;
          this->currSize=0;
          table=new Node*[totalSize];
          for(int i=0;i<totalSize;i++){
             table[i]=NULL;// assign NULL value for each table head
          }
       }
       void insert(string key,int val){
             int idx=hashFunction(key);// convert string to int
             Node* newNode=new Node(key,val);
             newNode->next=table[idx];
             table[idx]=newNode;
             currSize++;
             double lambda=currSize/(double)totalSize;
             if(lambda>1){
                rehash();// it's remove largest size of linked list
             }
       }
        bool exist(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
          while(temp!=NULL){
              if(temp->key==key){
                  return true;
               }
               temp=temp->next;
            }
          return false;
       }
       void remove(string key){
            int idx=hashFunction(key);
            Node* temp=table[idx];
            Node* prev=temp;
            while(temp!=NULL){
                if(temp->key==key){
                    if(temp==prev){// key value at head
                        table[idx]=temp->next;
                    }else{
                        prev->next=temp->next;
                    }
                    return;
                }
                prev=temp;
                temp=temp->next;
            }
       }
       int search(string key){
           int idx=hashFunction(key);
        Node* temp=table[idx];
          while(temp!=NULL){
              if(temp->key==key){
                  return temp->val;
               }
               temp=temp->next;
            }
          return -1;
       }
       void print(){
          cout<<"Key --- value"<<endl;
           for(int i=0;i<totalSize;i++){
                Node* temp=table[i];
                while(temp!=NULL){
                      cout<<temp->key<<"  "<<temp->val<<endl;
                      temp=temp->next;
                }
           }
       }
       

};
int main()
{   
    HashTable ht;
    ht.insert("Bangladesh",20);
    ht.insert("China",150);
    ht.insert("Nepal",15);
    ht.insert("Butan",27);
    ht.print();
    ht.remove("China");
    ht.print();
    ht.insert("India",120);
    ht.print();
    return 0;
}