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
void postOrder(Node* root){

    /*
    ==========================================
    DRY RUN OF postOrder(root)

    Postorder Rule:
        1. Traverse LEFT subtree
        2. Traverse RIGHT subtree
        3. Visit ROOT

    TREE:
                1
              /   \
             2     3
            / \     \
           4   5     6

    ==========================================
    CALL: postOrder(1)
        → go LEFT → postOrder(2)

    ------------------------------------------
    CALL: postOrder(2)
        → go LEFT → postOrder(4)

    ------------------------------------------
    CALL: postOrder(4)
        → go LEFT → postOrder(NULL)
            returns
        → go RIGHT → postOrder(NULL)
            returns
        → print 4
        (4 done)

    ------------------------------------------
    Back to node 2
        → go RIGHT → postOrder(5)

    CALL: postOrder(5)
        → go LEFT → postOrder(NULL)
            returns
        → go RIGHT → postOrder(NULL)
            returns
        → print 5
        (5 done)

    Now both children of 2 are processed
        → print 2

    ==========================================
    Back to ROOT (1)
        → go RIGHT → postOrder(3)

    ------------------------------------------
    CALL: postOrder(3)
        → go LEFT → postOrder(NULL)
            returns
        → go RIGHT → postOrder(6)

    CALL: postOrder(6)
        → go LEFT → postOrder(NULL)
            returns
        → go RIGHT → postOrder(NULL)
            returns
        → print 6
        (6 done)

    Both children of 3 processed
        → print 3

    ==========================================
    Finally at ROOT (1)
        → print 1

    ==========================================
    FINAL POSTORDER OUTPUT:
        4 5 2 6 3 1
    ==========================================
    */



    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    
    postOrder(root);
    return 0;
} 