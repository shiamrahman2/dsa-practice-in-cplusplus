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

Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}

Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void getInorderNode(Node* root,vector<int>&path){
    if(root==NULL){
        return;
    }
    getInorderNode(root->left,path);
    path.push_back(root->data);
    getInorderNode(root->right,path);
}

Node* BalancedBST(vector<int>nodes,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* currNode=new Node(nodes[mid]);
    currNode->left=BalancedBST(nodes,start,mid-1);
    currNode->right=BalancedBST(nodes,mid+1,end);
    return currNode;
}

Node* mergeBST(Node* root1,Node* root2){
    vector<int>nodes1;
    getInorderNode(root1,nodes1);

    vector<int>nodes2;
    getInorderNode(root2,nodes2);

    vector<int>marge;
    int i=0,j=0;

    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            marge.push_back(nodes1[i]);
            i++;
        }else{
            marge.push_back(nodes2[j]);
            j++;
        }
    }

    while(i<nodes1.size()){
        marge.push_back(nodes1[i]);
        i++;
    }
    while(j<nodes2.size()){
        marge.push_back(nodes2[j]);
        j++;
    }

    return BalancedBST(marge,0,marge.size()-1);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    postOrder(root->left);
    postOrder(root->right);
}

int main(){
    int arr1[]={2,1,4};
    Node* root1=buildBST(arr1,3);

    int arr2[]={9,3,12};
    Node* root2=buildBST(arr2,3);

    Node* margeRoot=mergeBST(root1,root2);

    postOrder(margeRoot);
    return 0;
}
