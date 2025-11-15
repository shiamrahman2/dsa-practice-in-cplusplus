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
Tree Created from Input:
            1
         /     \
        2       3
      /   \      \
     4     5      6

We call:
dimeterAndHeight(root)

This function returns:
    pair<diameter, height>

Let’s do a bottom-up dry run.

-------------------------------------------------------
CALL: dimeterAndHeight(4)

left = dimeterAndHeight(NULL) → (0,0)
right = dimeterAndHeight(NULL) → (0,0)

currDiameter = 0 + 0 + 1 = 1
finalDiameter = max(1, max(0,0)) = 1
finalHT = max(0,0) + 1 = 1

Return (1,1)

-------------------------------------------------------
CALL: dimeterAndHeight(5)

Same as node 4:

Return (1,1)

-------------------------------------------------------
CALL: dimeterAndHeight(2)

leftInfo = (1,1) from node 4
rightInfo = (1,1) from node 5

currDiameter = 1 + 1 + 1 = 3
finalDiameter = max(3, max(1,1)) = 3
finalHT = max(1,1) + 1 = 2

Return (3,2)

-------------------------------------------------------
CALL: dimeterAndHeight(6)

Same as node 4:

Return (1,1)

-------------------------------------------------------
CALL: dimeterAndHeight(3)

leftInfo = (0,0)
rightInfo = (1,1)

currDiameter = 0 + 1 + 1 = 2
finalDiameter = max(2, max(0,1)) = 2
finalHT = max(0,1) + 1 = 2

Return (2,2)

-------------------------------------------------------
CALL: dimeterAndHeight(1)

leftInfo = (3,2) from node 2
rightInfo = (2,2) from node 3

currDiameter = 2 + 2 + 1 = 5
finalDiameter = max(5, max(3,2)) = 5
finalHT = max(2,2) + 1 = 3

Return (5,3)

-------------------------------------------------------
MAIN OUTPUT:

Maximum Diameter between two leaves node: 5

-------------------------------------------------------

Final Result:
Diameter = 5
Height   = 3
*/


pair<int,int> dimeterAndHeight(Node* root){
          
    if(root==NULL){
        return make_pair(0,0);
    }
    // pair<diameter,ht>
    pair<int,int> leftInfo=dimeterAndHeight(root->left);
    pair<int,int> rightInfo=dimeterAndHeight(root->right);
    int currDiameter=leftInfo.second+rightInfo.second+1;
    int finalDiameter=max(currDiameter,max(leftInfo.first,rightInfo.first));
    int finalHT=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiameter,finalHT);

}
int main()
{   
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
   cout<<"Maximum Diameter between two leaves node:"<<dimeterAndHeight(root).first<<endl;
    return 0;
}