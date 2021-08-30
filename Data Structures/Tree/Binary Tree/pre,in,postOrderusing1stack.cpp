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

void everyIteration(Node *root){
    stack<pair<Node*,int> >st;
    vector<int> preOrder,inOrder,postOrder;
    st.push({root,1});
    while(!st.empty()){
        if(st.top().second==1){
            preOrder.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left) st.push({st.top().first->left,1});
        }
        else if(st.top().second==2){
            inOrder.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right) st.push({st.top().first->right,1});
        }
        else if(st.top().second==3){
            postOrder.push_back(st.top().first->data);
            st.pop();
        }
    }
    cout<<"preOrder: "<<endl;
    for(auto i:preOrder) cout<<i<<" ";

    cout<<endl<<"inOrder: "<<endl;
    for(auto i:inOrder) cout<<i<<" ";

    cout<<endl<<"postOrder: "<<endl;
    for(auto i:postOrder) cout<<i<<" ";
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

    everyIteration(root);
}