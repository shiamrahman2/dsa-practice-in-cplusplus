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
int KthAn(Node* root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }
    int leftDis=KthAn(root->left,node,k);
    int rightDis=KthAn(root->right,node,k);
    if(leftDis==-1 && rightDis==-1){
        return -1;
    }
    int validDis=leftDis==-1?rightDis:leftDis;
    if(validDis+1==k){
        cout<<"Kth Ancestor is -> "<<root->data<<endl;
    }
    return validDis+1;
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
   // LevelOrder(root);
   KthAn(root,6,1);
    return 0;
}