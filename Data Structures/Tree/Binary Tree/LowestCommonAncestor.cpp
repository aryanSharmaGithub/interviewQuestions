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

// This is to check and add values in path of the nodes vales from their roots. That is why we passed &path because we want the value back
bool getPath(Node *root,  int n, vector<int> &path){
    if(root == NULL){
        return false; // Classic base condition
    }

    // We will be assuming everything is correct or to say, Sab Changa Si.
    path.push_back(root->data); //Push the data in so that we can compare in the main LCA function
    if(root->data==n){
        return true; // True means that this value is present in our tree
    }
    if(getPath(root->left,n,path) || getPath(root->right,n,path)){
        return true; // This means if value returns true in left or right part of tree, you need to return true.
    }

    // Now we accept our fault (atleast we do lmao). So we pop back the values because they are of no use and then return false meaning
    // We dont have the value you been searching for. This does not mean value is not in tree. Maybe it is in opposite part of tree
    path.pop_back();
    return false;

}

int LCA(Node* root, int n1, int n2){
    // Basic idea is to create two vector, compare the path. The path where they will change directions from root will be their common ancestor
    vector<int> path1;
    vector<int> path2;

    // If we get false from either of them, that means we can not go further (because if either of them is not existing in tree, how can we
    // find the common ancestor).
    if(!getPath(root,n1,path1)||!getPath(root,n2,path2)){
        return -1;
    }

    // After passing all those conditions, we iterate the values over i to find the breaking point. Rest is easy to understand
    for(int i=0;i<path1.size() && path2.size();i++){
        if(path1.at(i)!=path2.at(i)){
            return path1.at(i-1);
        }
    }
    return -1; // We will return -1 implying there is some error in our code/input/int does not exist in tree.
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
    cout<<LCA(root,2,4)<<endl;
}