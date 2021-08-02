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


Node* constructBST(int preOrder[], int *preOrderIndex,int key, int min, int max, int n){
    // When all the nodes are finished scanning
    if(*preOrderIndex>=n){
        return NULL;
    }
    //Initially every node is null
    Node *root = NULL;

    // If they satisfy the condition of BST i.e. no same number and they should be in range of min and max. This is to prevent 7 to go in 5 when 6 is above 5.
    // There, it should go on right of 6 and that is why min would be INT_MIN (or anythin else, does not matter) and max would be 6. So root would pass.
    if(key> min && key<max){
        // If conditions are met. We make the new node root
        root = new Node(key);
        *preOrderIndex = *preOrderIndex + 1; // We increase the index number so that next int in array can be accessed

        // Means if indexes can still be accesed
        if(*preOrderIndex<n){
            // Here we are filling left subtree so its max should be the root key and min can be well, min 
            root->left = constructBST(preOrder,preOrderIndex,preOrder[*preOrderIndex],min,key,n);
        }
        if(*preOrderIndex<n){
            // Here we are filling right subtree so its min should be the root key and max can be well, max
            root->right = constructBST(preOrder,preOrderIndex,preOrder[*preOrderIndex],key,max,n);
        }
    }
    //We return the root at the end.
    return root;

}

void preOrderPrint(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main()
{
    int preOrder[]={10,2,1,13,11};
    int n = sizeof(preOrder)/sizeof(preOrder[0]);
    int preOrderIndex = 0;
    Node* root = constructBST(preOrder,&preOrderIndex,preOrder[0],INT_MIN,INT_MAX,n);
    preOrderPrint(root);
    cout<<endl;
}