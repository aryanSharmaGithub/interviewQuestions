#include<bits/stdc++.h>
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

    void sumNumber(Node *root, int &initSum, int &totalSum){
        if(!root) return;
        initSum = initSum*10 + root->data;
        if(!root->left && !root->right){
            totalSum+=initSum;
            initSum/=10;
            return;
        }
        sumNumber(root->left,initSum,totalSum);
        sumNumber(root->right,initSum,totalSum);
        initSum/=10;
    }
    
    int sumNumbers(Node* root) {
        int totalSum = 0;
        int n = 0;
        sumNumber(root,n,totalSum);
        return totalSum;
    }

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    cout<<sumNumbers(root)<<endl;
}