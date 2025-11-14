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

  /*
    ============================
    DRY RUN (buildTree)
    ============================

    nodes = [1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1]

    Step 1:
        idx = 0 → nodes[0] = 1
        Create Node(1)
        Build left subtree of 1

    Step 2:
        idx = 1 → nodes[1] = 2
        Create Node(2)
        Build left subtree of 2

    Step 3:
        idx = 2 → nodes[2] = 4
        Create Node(4)
        Build left subtree of 4

    Step 4:
        idx = 3 → nodes[3] = -1
        return NULL   (left child of 4)

    Step 5:
        idx = 4 → nodes[4] = -1
        return NULL   (right child of 4)

        Node 4 completed:
            4
           / \
         NULL NULL

    Step 6:
        Build right subtree of 2
        idx = 5 → nodes[5] = 5
        Create Node(5)

    Step 7:
        idx = 6 → nodes[6] = -1
        return NULL   (left child of 5)

    Step 8:
        idx = 7 → nodes[7] = -1
        return NULL   (right child of 5)

        Node 5 completed:
            5
           / \
         NULL NULL

    Node 2 completed:
            2
           / \
          4   5

    Step 9:
        Build right subtree of 1
        idx = 8 → nodes[8] = 3
        Create Node(3)

    Step 10:
        idx = 9 → nodes[9] = -1
        return NULL  (left child of 3)

    Step 11:
        idx = 10 → nodes[10] = 6
        Create Node(6)

    Step 12:
        idx = 11 → nodes[11] = -1
        return NULL  (left child of 6)

    Step 13:
        idx = 12 → nodes[12] = -1
        return NULL  (right child of 6)

        Node 6 completed:
            6
           / \
         NULL NULL

        Node 3 completed:
            3
           / \
         NULL  6

    FINAL TREE:
                1
              /   \
             2     3
            / \     \
           4   5     6
    ============================
    */
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
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<root->data<<endl;
    return 0;
}