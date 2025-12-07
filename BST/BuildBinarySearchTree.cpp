#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left=right=NULL;
        }
};


Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(root->data<val){
        root->right=insert(root->right,val);
    }else if(root->data>val){
        root->left=insert(root->left,val);
    }
    return root;
}
Node* BuildBST(int arr[],int n){ // O(NlogN);
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
 void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
 }
int main()
{   
    int arr[]={5,1,3,4,2,7,4893};
    int n=sizeof(arr)/sizeof(int);
    Node* root =BuildBST(arr,n);
    inOrder(root);
     return 0;
}