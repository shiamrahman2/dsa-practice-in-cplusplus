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

void KthHelper(Node* root,int k,int currLevel){
    if(root==NULL || currLevel>k){
        return;
    }
    if(k==currLevel){
        cout<<root->data<<" ";
    }
    KthHelper(root->left,k,currLevel+1);
    KthHelper(root->right,k,currLevel+1);
}
void KthLevel(Node* root,int k){ 
    // interview question give me only two value
    KthHelper(root,k,1);
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,4,-1,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    KthLevel(root,3);
    return 0;
}