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

// Case 1
void printSubtreeNodes(Node *root, int k){
    if(root==NULL || k<0){ //End of tree or k is an invalid distance. Both corner case covered :)
        return;
    }

    if(k==0){
        cout<<root->data<<" "; //Distance reached
        return;
    }

    printSubtreeNodes(root->left,k-1); //Search for left
    printSubtreeNodes(root->right,k-1); // Search for right
}

// Case 2
int printNodesAtK(Node *root,Node *target, int k){
    // This is the base condition which basically means if root is null then say sorry we dont have the target you were looking for
    // (because that is where this condition will come in place). Like in our eg target was node 2 so when we took left->left of 2
    // (i.e. 2->left = 4->left = NULL), it returns NULL meaning the target is not here.
    if(root == NULL){
        return -1;
    }

    // If we found out the target as root, we will pass it and k (distance in printSubtree nodes where we will print the distance nodes)
    if(root==target){
        printSubtreeNodes(root,k);
        return 1; // We will return 1 just to imply we found the target node we were looking for. (return 1 because we looked for
        // root->left and that is 1 distance away from root.
    }
    // First, the above condition will work for root = 1 but it wont pass as 1!=2 so it will come here.
    // The whole two chunk of codes means first we will traverse to left side of root to find the tagret. If target is not on that
    // side, it will return -1 (cuz root will eventually be NULL) and below condition will never take place. If we find it, we will
    // print the digits and then go on.
    int dl = printNodesAtK(root->left,target,k);

    //If dl!=-1, then it means that we found our node in the left part of root. Then we will check if distance from left child == k.
    // If it is, that means it can also be travelled from the target node.
    if(dl!=-1){
        if(dl==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right,k-dl-1); //We will print with right of root as root (as root of left would be explored till now)
            // We did k-dl-1 because k-dl is understandable (distance to travel - distance to travel to the root). but we did -1 more because
            // we are not only travelling to root but we are travelling to root->right so it is one more distance.
        }
    }

    // All of the same stuff for right too.
    int dr = printNodesAtK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left,k-dl-2);
        }
    }
    return -1; // This means we could not find the target in left and right subtree (will happen after leaf nodes or if target is not
    // present in the tree).
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
    printNodesAtK(root,root->left,1);
    cout<<endl;
}