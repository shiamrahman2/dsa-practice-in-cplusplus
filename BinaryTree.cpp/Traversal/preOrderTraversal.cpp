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

// preorder Traversal

void preOrder(Node* root){

   /*
    ==========================================
    DRY RUN OF preOrder(root)

    Preorder Rule:
        1. Visit ROOT
        2. Traverse LEFT subtree
        3. Traverse RIGHT subtree

    TREE:
                1
              /   \
             2     3
            / \     \
           4   5     6

    ==========================================
    CALL: preOrder(1)
        → print 1
        → call preOrder(2)

    ------------------------------------------
    CALL: preOrder(2)
        → print 2
        → call preOrder(4)

    ------------------------------------------
    CALL: preOrder(4)
        → print 4
        → call preOrder(NULL left of 4)
            returns
        → call preOrder(NULL right of 4)
            returns
        (4 done)

    ------------------------------------------
    Back to node 2
    → call preOrder(5)

    CALL: preOrder(5)
        → print 5
        → call preOrder(NULL left of 5)
            returns
        → call preOrder(NULL right of 5)
            returns
        (5 done)

    (2 subtree completed)

    ==========================================
    Back to ROOT (1)
    → call preOrder(3)

    CALL: preOrder(3)
        → print 3
        → call preOrder(NULL left of 3)
            returns
        → call preOrder(6)

    CALL: preOrder(6)
        → print 6
        → call preOrder(NULL left of 6)
            returns
        → call preOrder(NULL right of 6)
            returns
        (6 done)

    (3 subtree completed)

    ==========================================
    FINAL PREORDER OUTPUT:
        1 2 4 5 3 6
    ==========================================

    */ 
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    preOrder(root);
    return 0;
}