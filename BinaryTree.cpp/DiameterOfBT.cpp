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

/*
Tree Structure from input:
            1
         /     \
        2       3
      /   \      \
     4     5      6

---------------------------------------
Dry Run of diaMeterofBT(root = 1)

diameter(node):
    if node == NULL → return 0

-----------------------------------------------------
Call: diaMeterofBT(1)

    Compute left subtree diameter:
        diaMeterofBT(2)

    Compute right subtree diameter:
        diaMeterofBT(3)

    currDia at node 1:
        = Height(left) + Height(right) + 1
        left height  = 2 (node 2 → nodes 4 or 5)
        right height = 2 (node 3 → node 6)
        currDia = 2 + 2 + 1 = 5

-----------------------------------------------------
Call: diaMeterofBT(2)

    left → diaMeterofBT(4)
    right → diaMeterofBT(5)

    currDia at node 2:
        Height(4) = 1
        Height(5) = 1
        currDia = 1 + 1 + 1 = 3

-----------------------------------------------------
Call: diaMeterofBT(4)

    left → NULL → 0
    right → NULL → 0

    currDia at node 4:
        = 0 + 0 + 1 = 1

    leftDia = 0
    rightDia = 0
    return max(1, 0, 0) = 1

-----------------------------------------------------
Call: diaMeterofBT(5)  (same as node 4)

    currDia = 1
    return 1

-----------------------------------------------------
Back to node 2:
    leftDia = 1
    rightDia = 1
    currDia = 3
    return max(3,1,1) = 3

-----------------------------------------------------
Call: diaMeterofBT(3)

    left → NULL → 0
    right → diaMeterofBT(6)

    currDia at node 3:
        Height(NULL) = 0
        Height(6) = 1
        currDia = 0 + 1 + 1 = 2

-----------------------------------------------------
Call: diaMeterofBT(6)

    currDia = 1
    return 1

-----------------------------------------------------
Back to node 3:
    leftDia = 0
    rightDia = 1
    currDia = 2
    return max(2,0,1) = 2

-----------------------------------------------------
Back to node 1:
    leftDia = 3
    rightDia = 2
    currDia = 5

Final diameter = max(5,3,2) = 5

---------------------------------------
Output:
Maximum Difference Between Two Leaves Node: 5
*/


int HeightOfBT(Node* root){
    if(root==NULL)
       return 0;
    int leftHT=HeightOfBT(root->left);
    int rightHT=HeightOfBT(root->right);
    return max(leftHT,rightHT)+1;
}
int diaMeterofBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int currDia=HeightOfBT(root->left)+HeightOfBT(root->right)+1;
    int leftDia=diaMeterofBT(root->left);
    int rightDiam=diaMeterofBT(root->right);
    return max(currDia,max(leftDia,rightDiam));
}
int main()
{   
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Maximum Difference Between Two Leaves Node:"<<diaMeterofBT(root)<<endl;
    return 0;
}