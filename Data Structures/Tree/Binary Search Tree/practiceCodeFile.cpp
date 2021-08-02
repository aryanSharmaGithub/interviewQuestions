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

Node* constructBST(int preOrder[],int *preOrderIndex, int key, int min, int max, int n){
    if(*preOrderIndex>=n){
        return NULL;
    }

    Node *root = NULL;

    if(key>min && key<max){
        root = new Node(key);
        *preOrderIndex = *preOrderIndex +1;
        if(*preOrderIndex<n){
            root->left = constructBST(preOrder, preOrderIndex, preOrder[*preOrderIndex],min,key,n);
        }
        if(*preOrderIndex<n){
            root->right = constructBST(preOrder, preOrderIndex, preOrder[*preOrderIndex],key,max,n);
        }
    }
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