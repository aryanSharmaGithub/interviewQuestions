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

int maxSumPathUtil(Node *root, int &ans){
    if(!root) return 0;
    // Traversing through left and right subtree
    int left = maxSumPathUtil(root->left,ans);
    int right = maxSumPathUtil(root->right,ans);

    // maximumstraight path will be there when we assume that the node on which we are is in the path of the max sum. That is why we take max of left or right
    // (as path can be from either of side) and add our nodes data to it (and then we can pass to the above nodes, more on that later). Or we compare this with 
    // our node data (it can also happen that we are at the start of the max sum path. And if you are thinking that left/right + data > data, then values can be
    // negative too like humans).
    int maximumStraightPath = max(max(left,right)+root->data,root->data);
    // maxWithNodeAsRoot clears that if we are on a node from which max sum is changing its path. So here we will compare weather going from one path is good
    // or going from both path is better (like path sum wise). Whatever will be the ans will be updated here because if we think, maxWithNodeAsRoot is a special
    // case of maximumStraightPath when the path is bending. So, we need to take care of this case too.
    int maxWithNodeAsRoot = max(maximumStraightPath,left+right+root->data);
    // Now we will compare the previous held max with the currect record holder to check with path gave us the max sum and we will update it here.
    ans = max(maxWithNodeAsRoot,ans);
    // We are going to return maximumStriaghtPath here because of the above subset thing. To put it simply, we need to assume that node is in maximum straight path
    // even if it is maxWithNodeAsRoot becauseas the end it is also a node and it will check for path above it. Maybe that will have a even bigger number.
    // Tho we are returning maximumStraightPath, our ans is beign updated in background we need not worry about the real ans. Its been kept as a secret lol.
    return maximumStraightPath;
}

int maxSumPath(Node* root){
    // We take ans as min because we need to compare it (ans will be passed by reference so that we can return it later)
    int ans = INT_MIN;
    maxSumPathUtil(root,ans);
    return ans; // Our ans has sotred the maxSumPath and is ready to show the world.
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
    cout<<maxSumPath(root)<<endl;
}