#include<iostream>
#include<queue>
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
int heightOG(Node *root,int *height){
    int lh = 0, rh=0;
    int lDiameter=0,rDiameter=0;
    if(!root){
        *height = 0;
        return 0;
    }
    
    lDiameter = heightOG(root->left,&lh);
    rDiameter = heightOG(root->right,&rh);
    *height = max(lh,rh) +1;
    return max(lh+rh+1, max(lDiameter,rDiameter));
}
int heightLOL(Node *root){
    int h = 0;
    return heightOG(root,&h);;
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
    cout<<heightLOL(root)<<endl;
}