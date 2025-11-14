#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

void inOrder(Node* root){

    /*
    ==========================================
    DRY RUN OF inOrder(root)

    Inorder Rule:
        1. Traverse LEFT subtree
        2. Visit ROOT
        3. Traverse RIGHT subtree

    TREE:
                1
              /   \
             2     3
            / \     \
           4   5     6

    ==========================================
    CALL: inOrder(1)
        → go LEFT → inOrder(2)

    ------------------------------------------
    CALL: inOrder(2)
        → go LEFT → inOrder(4)

    ------------------------------------------
    CALL: inOrder(4)
        → go LEFT → inOrder(NULL)
            returns
        → print 4
        → go RIGHT → inOrder(NULL)
            returns
        (4 done)

    ------------------------------------------
    Back to node 2
        → print 2
        → go RIGHT → inOrder(5)

    CALL: inOrder(5)
        → go LEFT → inOrder(NULL)
            returns
        → print 5
        → go RIGHT → inOrder(NULL)
            returns
        (5 done)

    (2 subtree completed)

    ==========================================
    Back to ROOT (1)
        → print 1
        → go RIGHT → inOrder(3)

    ------------------------------------------
    CALL: inOrder(3)
        → go LEFT → inOrder(NULL)
            returns
        → print 3
        → go RIGHT → inOrder(6)

    CALL: inOrder(6)
        → go LEFT → inOrder(NULL)
            returns
        → print 6
        → go RIGHT → inOrder(NULL)
            returns
        (6 done)

    (3 subtree completed)

    ==========================================
    FINAL INORDER OUTPUT:
        4 2 5 1 3 6
    ==========================================
    */

    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    inOrder(root);
    return 0;
}
