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
void topView(Node* root){
    queue<pair<Node*,int>>Q;
    Q.push(make_pair(root,0));  //Known HD only root is 0;
    map<int,int>m;
    while(!Q.empty()){
        pair<Node*,int> curr=Q.front();
        Q.pop();
        Node* currNode=curr.first;
        int currHD=curr.second;
        if(m.count(currHD)==0){  //if currHorizontalDistance is unique Value;
             m[currHD]=currNode->data;
        }
        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,currHD-1);
            Q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,currHD+1);
            Q.push(right);
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main()
{   
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,4,-1,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    LevelOrder(root);
    topView(root);
    return 0;
}