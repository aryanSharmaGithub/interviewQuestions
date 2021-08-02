#include<iostream>
#include<queue>
#include<vector>
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

vector<int> bottomView(Node *root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    int rd = 
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
    vector<int> ans = bottomView(root);
    for(int i =0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}