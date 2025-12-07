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
void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
bool SearchInBST(Node* root,int key){
           if(root==NULL){
            return false;
           }
           if(root->data==key){
            return true;
           }else if(root->data>key){
                return SearchInBST(root->left,key);
           }else{
            return SearchInBST(root->right,key);
           }
}
int main()
{   
    int arr[]={5,1,3,4,2,7};
    int n=sizeof(arr)/sizeof(int);
    Node* root=BuildBST(arr,n);
    inOrder(root);
    cout<<endl;
    cout<<SearchInBST(root,7);
    return 0;
}