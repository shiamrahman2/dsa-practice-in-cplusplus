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

bool validBSTHelper(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<min->data){
        return false;
    }
    if(max!=NULL && root->data>max->data){
        return false;
    }
    return (validBSTHelper(root->left,min,root) && validBSTHelper(root->right,root,max));
}

bool validBST(Node* root){// bcz leetCode or Interview question only give root
   return validBSTHelper(root,NULL,NULL);
}
int main()
{   
    int arr[]={5,1,3,4,2,7};
    int n=sizeof(arr)/sizeof(int);
    Node* root=BuildBST(arr,n);
     root->data=20;
    cout<<validBST(root);
    return 0;
}