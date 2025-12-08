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
Node* BuildBST(int arr[],int n){// O(NlogN)
       Node* root=NULL;
       for(int i=0;i<n;i++){
          root=insert(root,arr[i]); // O(N)
       }
       return root;
}
Node* buildBSTFromSortedArray(vector<int>&arr,int start,int end){
    if(start>end){ // for single element start and end same
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBSTFromSortedArray(arr,start,mid-1);
    curr->right=buildBSTFromSortedArray(arr,mid+1,end);
    return curr;
}

void inOrder(Node* root,vector<int>&arr){
   if(root==NULL){
    return;
   }
   inOrder(root->left,arr);
   arr.push_back(root->data);
   inOrder(root->right,arr);
}
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{   
    int arr[]={3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    Node* root=BuildBST(arr,n);
    vector<int>element;
    inOrder(root,element);
    Node* newRoot=buildBSTFromSortedArray(element,0,n-1);
    preOrder(newRoot);
    return 0;
}