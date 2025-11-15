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


bool isIdentical(Node* root,Node* subRoot){
         
          if(root==NULL && subRoot==NULL){
            return true;
          }else if(root==NULL || subRoot==NULL){
            return false;
          }

          if(root->data!=subRoot->data){
             return false;
          }
           
          return isIdentical(root->left,subRoot->left)&& isIdentical(root->right,subRoot->right);
}

/*
dry run for this SubRoot

 vector<int> node1={2,4,-1,-1,5,-1,-1};


------------------------------------------------------------
START: isSubtree(root=1, subRoot=2)
------------------------------------------------------------
root = 1, subRoot = 2
1 != 2 → not identical → check left subtree

CALL isSubtree( root = 1->left = 2 , subRoot = 2 )

------------------------------------------------------------
CALL: isSubtree(root=2, subRoot=2)
------------------------------------------------------------
root = 2, subRoot = 2
Root values match → check isIdentical(2,2)

    CALL isIdentical(2,2)
    - Both NOT null
    - 2 == 2 → continue
    CALL isIdentical(4,4)
        - 4 == 4
        CALL isIdentical(NULL,NULL) → true
        CALL isIdentical(NULL,NULL) → true
        => subtree rooted at 4 is identical

    CALL isIdentical(5,5)
        - 5 == 5
        CALL isIdentical(NULL,NULL) → true
        CALL isIdentical(NULL,NULL) → true
        => subtree rooted at 5 is identical

    All matched → isIdentical returns TRUE

Since identical found → RETURN true for this call

------------------------------------------------------------
Return bubbles up:
isSubtree(root=2,subRoot=2) → TRUE

Now return TRUE to the top call
------------------------------------------------------------
Final OUTPUT:
isSubtree(root,subRoot) = TRUE
------------------------------------------------------------
*/




/*
===========================================================
SUBROOT TREE FROM {2,4,-1,-1,-1}
-----------------------------------------------------------
Index 0 → 2
Index 1 → 4
Index 2 → -1 → left of 4 = NULL
Index 3 → -1 → right of 4 = NULL
Index 4 → -1 → right of 2 = NULL

Final subRoot:
       2
      /
     4
===========================================================

MAIN TREE (root):
         1
       /   \
      2     3
    /  \     \
   4    5     6

===========================================================
START isSubtree(root=1, subRoot=2)
-----------------------------------------------------------
root = 1, subRoot = 2
1 != 2
→ Move to left subtree

CALL isSubtree(root=2, subRoot=2)
-----------------------------------------------------------
root = 2, subRoot = 2
root->data == subRoot->data
→ Check isIdentical(2,2)

CALL isIdentical(2,2):

    Compare root(2) with subRoot(2) → OK

    CALL isIdentical(4 , 4)
        Values equal → OK
        CALL isIdentical(NULL,NULL) → true
        CALL isIdentical(NULL,NULL) → true
        subtree rooted at 4 matches

    CALL isIdentical(5 , NULL)
        One NULL, one NOT NULL
        → return FALSE

isIdentical(2,2) returns FALSE
(because right subtree mismatch: main tree has 5 but subRoot has NULL)

→ isSubtree(root=2, subRoot=2) continues

Left subtree was false → check right subtree:
CALL isSubtree(root=5, subRoot=2)

-----------------------------------------------------------
CALL isSubtree(root=5, subRoot=2):
-----------------------------------------------------------
5 != 2
→ check left subtree: CALL isSubtree(NULL, subRoot=2)
    → returns FALSE
→ check right subtree: CALL isSubtree(NULL, subRoot=2)
    → returns FALSE

→ whole branch returns FALSE

-----------------------------------------------------------
Back to root=1:
Left subtree return was FALSE → check right subtree

CALL isSubtree(root=3, subRoot=2)
-----------------------------------------------------------
3 != 2
→ check left subtree (NULL)
→ check right subtree (6)

CALL isSubtree(root=6, subRoot=2)
6 != 2
→ check left NULL
→ check right NULL
→ return FALSE

-----------------------------------------------------------
No match found anywhere!
isSubtree(root, subRoot) → FALSE
===========================================================
FINAL RESULT: 0
===========================================================
*/


bool isSubtree(Node* root,Node* subRoot){
    
    // base case
    if(root==NULL && subRoot==NULL){
        return true;
    }else if(root==NULL || subRoot==NULL){
        return false;
    }

    if(root->data==subRoot->data){
        // identical check;
        if(isIdentical(root,subRoot)){
            // edge case check if further match 
            return true;
        }
    }
    bool leftSubTree=isSubtree(root->left,subRoot);
    if(!leftSubTree){
        return isSubtree(root->right,subRoot);
    }
    return true;
}

int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx=-1;
    Node* root=buildTree(nodes);
    vector<int> node1={2,4,-1,-1,-1};
    idx=-1;
    Node* subRoot=buildTree(node1);
    cout<<subRoot->data<<endl;
    cout<<isSubtree(root,subRoot)<<endl;
    return 0;
}