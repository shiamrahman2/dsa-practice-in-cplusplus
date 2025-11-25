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
void LevelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* currNode=q.front();
        q.pop();
        if(currNode==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
            }
        }else{
            cout<<currNode->data<<" ";
            if(currNode->left!=NULL){
                q.push(currNode->left);
            }
            if(currNode->right!=NULL){
                q.push(currNode->right);
            }
        }
    }
}
int transForm(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftOld=transForm(root->left);
    int rightOld=transForm(root->right);
    int currOld=root->data;
    root->data=leftOld+rightOld;
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    return currOld;
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    transForm(root);
    LevelOrder(root);
    return 0;
}