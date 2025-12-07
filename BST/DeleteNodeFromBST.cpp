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
Node* getInorderSuccessor(Node* root){
         while(root->left!=NULL){
            root=root->left;
         }
         return root;
}
Node* delNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){// delete in left subtree
        root->left=delNode(root->left,val);
    }else if(val>root->data){// delete in right subtree
        root->right=delNode(root->right,val);
    }else{  // if value match with root
        // case o1: No Child leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // case 02: Left or Right Child EXist
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }
        // case 03 : left and right child both exist
        Node* IS=getInorderSuccessor(root->right);// Inorder Successor Always lies in right subtree
        root->data=IS->data;
        root->right=delNode(root->right,IS->data);// Inorder Successor Exist root->right, which should delete after assign
        // That is the reason we assign root->right
        return root;
    }
    return root;// Never Execute This Line
}

int main()
{   
    int arr[]={8,5,10,3,6,11,1,4,14};
    int n=sizeof(arr)/sizeof(int);
    Node* root=BuildBST(arr,n);
    inOrder(root);
    cout<<endl;
     Node* root1=delNode(root,5);
     inOrder(root1);
    return 0;
}