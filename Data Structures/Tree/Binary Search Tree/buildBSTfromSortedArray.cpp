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

Node* buildBST(int arr[],int start, int end){
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node *root = new Node(arr[mid]);
    root->left = buildBST(arr,start,mid-1);
    root->right = buildBST(arr,mid+1,end);
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

int main()
{
    int sortedArray[]={1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = sizeof(sortedArray)/sizeof(sortedArray[0])-1;
    Node *root = buildBST(sortedArray,start,end);
    inOrder(root);
    cout<<endl;
}