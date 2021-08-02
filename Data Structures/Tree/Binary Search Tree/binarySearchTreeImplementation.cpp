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

Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* inOrderSucc(Node *root){
    Node *curr = root;
    while(curr!=NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node *root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data>key){
        root->left = deleteInBST(root->left,key); // Traverse to left (will help us when key == root->data)
    }

    else if(root->data<key){
        root->right = deleteInBST(root->right,key); // Traverse to right (will help us when key == root->data)
    }

    else{
        /*
            There are three cases.
            1.) Delete leaf node 2.) Delete node with 1 child 3.) Delete node with 2 children
        */
       // First two if will handle case 1 and 2. We store the value of root->right in temp and then delete that node. After that we return temp which will either
       // go to root->data>key or root->data<key so the value which was lost will return back (as this function was stored as root->left or root->right).
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // This is the 2 children condition. Here, we will take inOrder Successor, replace its value with the root and then delete the node.
        // First, we store the inOrder successor, then we copy root->data to inOrder succ data (so that inOrder succ is preserved). Then we delete the root->right
        // (where OG inorder successor was). We call deleteBST on right of root (inOrder succesor and we try to find the temp->data) and delete the last node.
        else{
            Node *temp = inOrderSucc(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
        }
    }
    return root; // We then return the root value again.
}

void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* isPresent(Node *root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data>key){
        return isPresent(root->left,key);
    }

    if(root->data == key){
        return root;
    }

    else return isPresent(root->right,key);
}

int main()
{
    Node* root = NULL;
    root = insertBST(root,5);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,7);
    inOrder(root);
    cout<<endl;
    deleteInBST(root,5);
    inOrder(root);
}