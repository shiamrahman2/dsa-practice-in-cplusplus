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
static int idx=-1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}
Node* LCA(Node* root,int n1,int n2){
    if(root==NULL){
        return root;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA=LCA(root->left,n1,n2);
    Node* rightLCA=LCA(root->right,n1,n2);
    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    return leftLCA==NULL?rightLCA:leftLCA;
}
int distance(Node* root,int n){
      if(root==NULL){
        return -1;
      }
      if(root->data==n){
          return 0;
      }
      int leftDis=distance(root->left,n);
      int rightDis=distance(root->right,n);
      if(leftDis!=-1){
        return leftDis+1;
      }
      if(rightDis!=-1){
        return rightDis+1;
      }
      return -1;
}
int MinDisBNode(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int dis1=distance(lca,n1);
    int dis2=distance(lca,n2);
    return dis1+dis2;
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
   // LevelOrder(root);
    int minDis=MinDisBNode(root,4,5);
    cout<<"Minimum distance between two node->"<<minDis<<endl;
    return 0;
}