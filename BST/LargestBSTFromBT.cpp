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

class Info{
    public:
       bool isBST;
       int mn;
       int mx;
       int sz;
       Info(bool isBST,int mn,int mx,int sz){
            this->isBST=isBST;
            this->mn=mn;
            this->mx=mx;
            this->sz=sz;
       }
 };

static int mxSize;
static Node* largestNode;
Info* largestBST(Node* root){
      // base case 01
      if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);
      }
        
      // base 02
    //   if(root==NULL){
    //     return NULL;
    //   }
    //   if(root->left==NULL && root->right==NULL){
    //     return new Info(true,root->data,root->data,1);
    //   }
      Info* leftInfo=largestBST(root->left);
      Info* rightInfo=largestBST(root->right);

      int currMin=min(root->data,min(leftInfo->mn,rightInfo->mn));
      int currMax=max(root->data,max(leftInfo->mx,rightInfo->mx));
      int currSZ=leftInfo->sz+rightInfo->sz+1;
      if(leftInfo->isBST && rightInfo->isBST && leftInfo->mx<root->data && root->data<rightInfo->mn){
        if(currSZ>mxSize){
             mxSize=max(mxSize,currSZ);
            largestNode=root;
        }
        return new Info(true,currMin,currMax,currSZ);
      }
       return new Info(false,currMin,currMax,currSZ);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

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
int main()
{   
    vector<int> nodes = {50,30,5,-1,-1,20,-1,-1,60,45,-1,-1,70,65,-1,-1,80,-1,-1};
    Node* root=buildTree(nodes);
    cout<<root->data<<endl;
    largestBST(root);
    cout<<mxSize<<endl;
    inOrder(largestNode);
    return 0;
}
