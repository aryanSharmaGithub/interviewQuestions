#include<iostream>
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

void floorCeil(Node *root,int k,Node* &floor,Node* &ceil){
    if(!root) return;
    if(root->data == k){
        cout<<root->data<<" "<<root->data;
        return;
    }
    else if(root->data < k){
        floor = root;
        floorCeil(root->right,k,floor,ceil);
    }
    else{
        ceil = root;
        floorCeil(root->left,k,floor,ceil);
    }
}

vector<int> floorCeilOG(Node*root,int k){
    vector<int> ans;
    if(!root) return ans;
    Node *floor = NULL;
    Node *ceil = NULL;
    floorCeil(root,k,floor,ceil);
    ans.push_back(floor->data);
    ans.push_back(ceil->data);
    return ans;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    vector<int> ans = floorCeilOG(root,5);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}