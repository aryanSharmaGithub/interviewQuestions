#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){
    // Base case will be if root has no value or it is the leaf node
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }

    //If we dont any left value (because our aim is to take all left value in right)
    if(root->left!=NULL){
        flatten(root->left); // We will go till the last left node
        Node* node = root->right; //New node to hold all the right subtree values
        root->right = root->left; //Transfering left subtree values to right
        root->left = NULL; // making the left NULL because we need linear tree

        Node *t = root->right; //Making a pointer for the OG right subtree
        while(t->right!=NULL){ 
            t=t->right; // Traversing till last node
        }

        t->right = node; //attaching right values to t
    }

    flatten(root->right); //Doing it again for other subtrees maybe.
}

void inOrder(Node* root){
    //Recursive Method
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    flatten(root);
    inOrder(root);
    cout<<endl;

}