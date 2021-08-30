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

void inorderTraversal(Node *root){
    stack<Node*> st;
    Node *node = root;

    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top(); st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
}

void preorderTraversal(Node *root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        cout<<st.top()->data<<" ";
        Node *curr = st.top();
        st.pop();
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);
    }
}

void postOrder2Stack(Node *root){
    stack<Node*> st;
    stack<Node*> sTop;
    st.push(root);
    while(!st.empty()){
        sTop.push(st.top());
        Node *curr = st.top(); st.pop();
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
    while(!sTop.empty()){
        cout<<sTop.top()->data<<" ";
        sTop.pop();
    }
}

void postOrder1Stack(Node *root){
    stack<Node*>st;
    Node *curr = root;

    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            Node *temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }else curr = temp;
        }
    }
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
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"PostOrder using 2 stack"<<endl;
    postOrder2Stack(root);
    cout<<endl;
    cout<<"PostOrder using 1 stack"<<endl;
    postOrder1Stack(root);
}