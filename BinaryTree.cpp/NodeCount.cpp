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
    /*
        Function: countNode(root)
        Purpose : Count the total number of nodes in the binary tree
        Approach: Recursive → Total = leftCount + rightCount + 1

        Given Tree (from input):
                     1
                  /     \
                 2       3
               /   \       \
              4     5       6

        Dry Run:

        countNode(1)
            -> countNode(2)
                -> countNode(4)
                    -> countNode(NULL) = 0
                    -> countNode(NULL) = 0
                    -> return 0 + 0 + 1 = 1   [node 4]
                -> countNode(5)
                    -> countNode(NULL) = 0
                    -> countNode(NULL) = 0
                    -> return 0 + 0 + 1 = 1   [node 5]
                -> return 1 + 1 + 1 = 3       [node 2 subtree]
            -> countNode(3)
                -> countNode(NULL) = 0        [left of 3]
                -> countNode(6)
                    -> countNode(NULL) = 0
                    -> countNode(NULL) = 0
                    -> return 0 + 0 + 1 = 1   [node 6]
                -> return 0 + 1 + 1 = 2       [node 3 subtree]
            -> return 3 + 2 + 1 = 6           [total nodes]

        Final Node Count = 6
    */

    if(root==NULL){
        return 0;
    }

    int leftCountNode = countNode(root->left);   // count nodes in left subtree
    int rightCountNode = countNode(root->right); // count nodes in right subtree

    return leftCountNode + rightCountNode + 1;   // +1 for current node
}


int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Total Count Node="<<countNode(root)<<endl;
    return 0;
}