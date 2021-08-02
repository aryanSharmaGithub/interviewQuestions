#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(root->data>val){
        root->left = insertBST(root->left,val);
    }

    if(root->data<val){
        root->right = insertBST(root->right,val);
    }

    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool isBSTcheck(Node *root, Node *min=NULL, Node *max=NULL){
    if(root==NULL ){
        return true;
    }

    // If min is not null and the data of node is less than the min of the node, the it means BST is invalid
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    // If max is not null and the data of node is greater than the max of the node, the it means BST is invalid
    if(max!=NULL && root->data >= max->data){
        return false;
    }
    // it will check one by one for left and right values. min for left will be min and max will be root cuz well, BST. Vice versa for right.
    bool leftValue = isBSTcheck(root->left,min,root);
    bool rightValue = isBSTcheck(root->right, root, max);
    
    // Return both values
    return leftValue & rightValue;
}

int main()
{
    Node* root = NULL;
    root = insertBST(root,5);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,7);
    inOrder(root);
    cout<<endl;
    cout<<isBSTcheck(root,NULL,NULL);
    cout<<endl;
}