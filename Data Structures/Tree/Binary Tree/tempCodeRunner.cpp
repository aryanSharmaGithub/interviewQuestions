#include<iostream>
#include<queue>
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

bool checkIdentical(Node *root1, Node *root2){
    if(!root1 && !root2) return true;
    else if(!root1 || !root2) return false;
    else{
        bool condition1 = (root1->data == root2->data);
        bool condition2 = checkIdentical(root1->left,root2->left);
        bool condition3 = checkIdentical(root1->right,root2->right);
        return condition1 && condition2 && condition3;
    }
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
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    cout<<checkIdentical(root,root2)<<endl;
}