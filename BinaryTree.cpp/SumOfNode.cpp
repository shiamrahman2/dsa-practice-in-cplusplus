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

int countNode(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCountNode=countNode(root->left);
    int rightCountNode=countNode(root->right);
    return leftCountNode+rightCountNode+1;
}

int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Total Count Node="<<countNode(root)<<endl;
    return 0;
}