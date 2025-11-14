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

int heightOfBT(Node* root){
    /*
        Function: heightOfBT(root)
        Purpose : Returns maximum height of a binary tree
        Approach: Recursive → Height = max(leftHeight, rightHeight) + 1

        Dry Run for Tree: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

        Tree structure:
                     1
                  /     \
                 2       3
               /   \       \
              4     5       6

        Step-by-step:

        heightOfBT(1)
            -> heightOfBT(2)
                -> heightOfBT(4)
                    -> heightOfBT(NULL) = 0
                    -> heightOfBT(NULL) = 0
                    -> currHT = max(0,0)+1 = 1  [height of node 4]
                -> heightOfBT(5)
                    -> heightOfBT(NULL) = 0
                    -> heightOfBT(NULL) = 0
                    -> currHT = max(0,0)+1 = 1  [height of node 5]
                -> currHT for node 2 = max(1,1)+1 = 2
            -> heightOfBT(3)
                -> heightOfBT(NULL) = 0   (left subtree of 3)
                -> heightOfBT(6)
                    -> heightOfBT(NULL)=0
                    -> heightOfBT(NULL)=0
                    -> currHT = 1  [height of node 6]
                -> currHT for node 3 = max(0,1)+1 = 2
            -> currHT for root 1 = max(2,2)+1 = 3

        Final Answer: Height = 3
    */

    if(root==NULL)
       return 0;

    int left=heightOfBT(root->left);   // height of left subtree
    int right=heightOfBT(root->right); // height of right subtree

    int currHT=max(left,right)+1;      // take maximum and add 1
    return currHT;
}

int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Maximum Height of Tree:"<<heightOfBT(root)<<endl;
    return 0;
}