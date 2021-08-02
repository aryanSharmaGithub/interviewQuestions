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

void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int search(int inOrder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postOrder[],int inOrder[], int start, int end){
    static int index = end;
    if(start>end){
        return NULL;
    }
    int curr = postOrder[index];
    index--;
    Node *node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos = search(inOrder,start,end,curr);
    node->right = buildTree(postOrder,inOrder,pos+1,end);
    node->left = buildTree(postOrder,inOrder,start,pos-1);
    return node;
}

int main()
{
    int postOrder[]={4,2,5,3,1};
    int inOrder[]={4,2,1,5,3};
    int n = sizeof(postOrder)/sizeof(postOrder[0]);
    Node* ans =  buildTree(postOrder,inOrder,0,n-1);
    printInorder(ans);
    cout<<endl;
}