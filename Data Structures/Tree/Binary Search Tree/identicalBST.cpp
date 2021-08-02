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

bool isIdentical(Node *root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    else{
        bool condition1 = (root1->data == root2->data);
        bool condition2 = isIdentical(root1->left,root2->left);
        bool condition3 = isIdentical(root1->right,root2->right);
        return condition1 && condition2 && condition3;
        // if(condition1 && condition2 && condition3){
        //     return true;
        // }
        // else return false;
    }

}
   
int main()
{
    /* 
                 12
                / \
               9  15
              / \
             5  10
    */
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    
    Node *root1 = new Node(12);
    root1->left = new Node(9);
    root1->right = new Node(15);
    root1->left->left = new Node(5);
    root1->left->right = new Node(11);

    cout<<isIdentical(root,root1);
    cout<<endl;
}