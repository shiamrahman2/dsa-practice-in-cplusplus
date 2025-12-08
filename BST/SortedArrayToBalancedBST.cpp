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

Node* buildBSTFromSortedArray(int arr[],int start,int end){
    if(start>end){ // for single element start and end same
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBSTFromSortedArray(arr,start,mid-1);
    curr->right=buildBSTFromSortedArray(arr,mid+1,end);
    return curr;
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
    Node* root=buildBSTFromSortedArray(arr,0,n-1);
    preOrder(root);
    return 0;
}