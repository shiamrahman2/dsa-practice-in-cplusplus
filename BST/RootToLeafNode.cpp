#include<bits/stdc++.h>
using namespace std;
#define print cout<<endl;
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
void printPath(vector<int>path){
    cout<<"Path->";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    print;
}
void pathHelper(Node* root, vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printPath(path);
        path.pop_back();// before backtracking remove last element of vector
        return;
    }
    pathHelper(root->left,path);
    pathHelper(root->right,path);
   path.pop_back();// initially assign value remove from vector path
 }
void RootToLeafNode(Node* root){
  vector<int> path;
    pathHelper(root,path);
    return;
}
int main()
{   
    int arr[]={8,5,10,3,6,11,1,4,14};
    int n=sizeof(arr)/sizeof(int);
    Node* root=BuildBST(arr,n);
    inOrder(root);
    print;
    RootToLeafNode(root);
    return 0;
}