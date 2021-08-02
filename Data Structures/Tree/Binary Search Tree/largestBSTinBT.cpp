#include<iostream>
#include<stack>
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

// We created an struct which will have all the values we require. Size to return the size of tree, max min to return the max min of subtree, ans to return
// ans (size of largest BST) and a condition to check if the subtree is even BST
class info{
    public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBST(Node *root){
    // If the node is NULL, max min will be opp (because we need to comapre afterwards). ans will be 0 and size will be 0 (cuz well, NULL). Tho it will be BST
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    // If the node is leaf node, it is a BST of size 1 and max min = root->data;
    if(root->left == NULL && root->right == NULL){
        return {1,root->data,root->data,1,true};
    }

    // We create new infoLeft and infoRight for left and right subtrees
    info infoLeft = largestBST(root->left);
    info infoRight = largestBST(root->right);
    info curr; // Another to specify the current node (which we will treat as root node of the subtree as technically we need the subtree)
    curr.size = (1 + infoLeft.size + infoRight.size); // including the size of root node (curr).
    if(infoLeft.isBST && infoRight.isBST && infoLeft.max<root->data && infoRight.min>root->data){ // All the conditions required to declare a tree BST
        curr.min = min(infoLeft.min, min(infoRight.min,root->data)); // roots min would be min of right subtree or left subtree or maybe the root data
        curr.max = max(infoRight.max, max(infoLeft.max,root->data)); // same for max

        curr.ans = curr.size; // as it is BST, its size is the largest BST atm
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(infoLeft.ans,infoRight.ans); // If it is not BST, we return the ans of the last greatest BST.
    curr.isBST = false; //false for the node (not for whole)
    return curr;
}


int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    root->right = new Node(18);

    cout<<"Largest BST = "<<largestBST(root).ans<<endl;
}