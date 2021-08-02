#include<iostream>
using namespace std;

// Node is same like the LL ones.
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

void preOrder(node* root){
    // Recursive Method
    if(root == NULL){ // Base condition
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void inOrder(node* root){
    //Recursive Method
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    //Recursive Method
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    class node* root = new node(1); // This will invoke the new root node. Others are just derivative of this node
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}