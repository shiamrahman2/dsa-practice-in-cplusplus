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
          return idx;
     }
     void rehash(){
        Node** oldTable=table;
        int oldSize=totalSize;
        totalSize=2*oldSize;
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
       HashTable(int size=5){
          this->totalSize=size;
          this->currSize=0;
          table=new Node*[totalSize];
          for(int i=0;i<totalSize;i++){
             table[i]=NULL;
          }
       }
       void insert(string key,int val){
             int idx=hashFunction(key);
             Node* newNode=new Node(key,val);
             Node* head=table[idx];
             newNode->next=head;
             head=newNode;
             currSize++;
             double lambda=currSize/(double)totalSize;
             if(lambda>1){
                rehash();
             }
       }
       void remove(string key){

       }
       int search(string key){

       }
       

};
int main()
{   
    return 0;
}