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
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }else{
                q.push(NULL);
            }
        }else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
bool rootToNode(Node* root,int n,vector<int>& path){
       if(root==NULL){
        return false;
       } 
       path.push_back(root->data);
       if(root->data==n){
        return true;
       }
       bool left=rootToNode(root->left,n,path);
       bool right=rootToNode(root->right,n,path);
       if(left || right){
        return true;
       }
       path.pop_back();
       return false;
}
void LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;
    rootToNode(root,n1,path1);
    rootToNode(root,n2,path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size() && path2.size();i++,j++){
        if(path1[i]!=path2[i]){
            break;
        }
        lca=path1[i];
    }
    cout<<lca<<endl;
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
   // LevelOrder(root);
   LCA(root,4,6);
    return 0;
}