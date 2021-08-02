#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
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

vector<int> bottom(Node *root){
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> m; // key is distance and val is frequency of level visited
    queue<pair<Node*,int> > q; // Node and its distance;
    
    q.push({root,0});
    while(!q.empty()){
        // Relative distance (relative to root);
        int n = q.size();
            int rd = q.front().second; 
            Node *node = q.front().first;
            q.pop();
            // if(m[rd]==0){
                m[rd]=node->data;
                // ans.push_back(node->data);
            // }
            if(node->left){
                q.push({node->left,rd-1});
            }
            if(node->right){
                q.push({node->right,rd+1});
            }
        
    }
    map<int,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        ans.push_back(it->second);
    }
    return ans;
}

//Top View
vector<int> topView(Node *root){
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> m; // key is distance and val is frequency of level visited
    queue<pair<Node*,int> > q; // Node and its distance;
    
    q.push({root,0});
    while(!q.empty()){
        // Relative distance (relative to root);
        int n = q.size();
            int rd = q.front().second; 
            Node *node = q.front().first;
            q.pop();
            if(m[rd]==0){
                m[rd]=node->data;
                // ans.push_back(node->data);
            }
            if(node->left){
                q.push({node->left,rd-1});
            }
            if(node->right){
                q.push({node->right,rd+1});
            }
        
    }
    map<int,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        ans.push_back(it->second);
    }
    return ans;
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
    //leftView(root);
    cout<<"Bottom View is: ";
    vector<int> ans = bottom(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
    vector<int> ans2 = topView(root);
    cout<<"Top view is: ";
    for(int i=0;i<ans2.size();i++){
        cout<<ans2.at(i)<<" ";
    }
    cout<<endl;
}