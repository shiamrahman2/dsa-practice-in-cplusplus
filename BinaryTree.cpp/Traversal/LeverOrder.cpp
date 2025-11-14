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

     /*
    ==========================================
    DRY RUN OF LevelOrder(root)

    LEVEL-ORDER RULE (BFS):
        1. Use queue
        2. Push root first
        3. Push NULL as level marker
        4. While queue not empty:
            → Pop front
            → If NULL, print newline
            → Else, print node, push left & right children

    TREE:
                1
              /   \
             2     3
            / \     \
           4   5     6

    ==========================================
    Initial queue: [1, NULL]

    Step 1:
        curr = 1
        print 1
        push left child 2
        push right child 3
        queue: [NULL, 2, 3]

    Step 2:
        curr = NULL
        print newline
        queue not empty → push NULL at end
        queue: [2, 3, NULL]

    Step 3:
        curr = 2
        print 2
        push left child 4
        push right child 5
        queue: [3, NULL, 4, 5]

    Step 4:
        curr = 3
        print 3
        left child = NULL → nothing
        push right child 6
        queue: [NULL, 4, 5, 6]

    Step 5:
        curr = NULL
        print newline
        queue not empty → push NULL
        queue: [4, 5, 6, NULL]

    Step 6:
        curr = 4
        print 4
        left & right NULL → nothing
        queue: [5, 6, NULL]

    Step 7:
        curr = 5
        print 5
        left & right NULL → nothing
        queue: [6, NULL]

    Step 8:
        curr = 6
        print 6
        left & right NULL → nothing
        queue: [NULL]

    Step 9:
        curr = NULL
        print newline
        queue empty → break

    ==========================================
    FINAL LEVEL ORDER OUTPUT (line by line):
        1
        2 3
        4 5 6
    ==========================================
    */


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
int main()
{   
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    LevelOrder(root);
    return 0;
}