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

void calcPointer(Node* root, Node **first, Node **mid, Node **last, Node **prev){
    if(root == NULL){
        return;
    }

    calcPointer(root->left,first,mid,last,prev);

    if(*prev!=NULL && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right,first, mid, last, prev);

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(Node* root){
    Node *first=NULL,*mid=NULL,*last=NULL,*prev=NULL;
    calcPointer(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data),&(last->data));
    }
    else if(first && mid){
        swap(&(first->data),&(mid->data));
    }
}

void inOrder(Node *root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(15);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    inOrder(root);
    cout<<endl;
    restoreBST(root);
    inOrder(root);
    cout<<endl;
}