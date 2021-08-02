#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    class Node* left;
    class Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> solve(Node* root, int B) {
    if(root->data==B)
    {
        return {};
    }
    queue<Node*> q;
    vector<int> ans;
    if(!root) return ans;
    q.push(root);
    int found=false;
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left && curr->left->data==B || curr->right && curr->right->data==B)
            found = true;
            else{
                if(curr->left) {temp.push_back(curr->left->data); q.push(curr->left);}
                if(curr->right){temp.push_back(curr->right->data); q.push(curr->right);}
            } 
            
        }
        if(found){
            ans = temp;
            break;
        }
    }
    return ans;
}

int main()
{
    class Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(7);
    root->left->left = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(8);
    root->right->left->left = new Node(9);

    vector<int> ans = solve(root,7);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
}