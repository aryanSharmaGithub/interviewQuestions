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

bool heightBalance(Node*root, int *height){
    if(root==NULL){ //Base case
        return true;
    }

    int lh = 0,rh =0; // Assign left child height, right child height
    if(heightBalance(root->left, &lh)==false){ // We find the left child of the tree
        return false; // It will return false when lh-rh>1 (see the last condition below and rememeber we have called the function above to return it)
    }

    if(heightBalance(root->right, &rh)==false){ // Same as above but for right side
        return false;
    }

    *height = max(lh,rh)+1; //We calculate height of tree (here tree will be = lh or rh). This means we will calculate height of specific node
    if(abs(lh-rh)<=1){ //Check if diff matches 1 or less than 1
        return true; // Return true for this (means for the perticlar root, the tree is balanced). If we did this to every left and right node.
                    // if it still comes true, then our tree is balanced
    }
    else return false;
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
    int height = 0;
    cout<<heightBalance(root,&height)<<endl;
}