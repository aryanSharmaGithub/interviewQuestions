#include<iostream>
#include<map>
#include<vector>
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

void verOrderPrint(Node *root,int distance, map<int, vector<int> > &tree){
    if(root == NULL){
        return;
    }
    tree[distance].push_back(root->data);
    verOrderPrint(root->left,distance-1,tree);
    verOrderPrint(root->right,distance+1,tree);
}

int main()
{
    // int arr[]={1,2,2,2,2,1,1,1,1,};
    // int n = sizeof(arr)/sizeof(arr[]);
    Node *root = new Node(99);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right = new Node(4);
    root->right->left = new Node(14);
    root->right->right = new Node(6);
    map <int,vector<int> >tree;
    int distance = 0;
    verOrderPrint(root,distance,tree);
    map <int,vector<int> > :: iterator it;
    for(it = tree.begin(); it!=tree.end(); it++){
        for(int i = 0;i<(it->second).size();i++){
            sort((it->second).begin()+1,(it->second).end());
            cout<<(it->second).at(i)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}