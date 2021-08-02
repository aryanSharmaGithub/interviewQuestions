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

void inOrderPrint(Node* root){
    //Recursive Method
    if(root==NULL)
    return;

    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}


int search(vector<int> inOrder, int start,int end, int curr ){
    for(int i=start;i<=end;i++){ //we start from not 0 because when we will search for right side then i should be pos+1 (which is passed as start here)
        if(inOrder.at(i)==curr){ // When we will find the preOrder value in inOrder (preOrder value is curr which we declared in buildTree)
            return i; // We return the value so that left right tree building operations could take place
        }
    }
    return -1; // This condition will never happen but incase this happens, this just means there was some mistake in our preOrder or inOrder array
}

Node* buildTree(vector<int>preOrder,vector<int>inOrder, int start, int end){
    // This will be used to traverse the preOrder because preOrder is the root element and when we pass this in preOrder,
    // the left side of array gives the left side of tree and right side of array gives right side of root.
    static int index = 0; 

    if(start>end){
        return NULL; //base condition to see this ending
    }

    int curr = preOrder.at(index); // curr will be used to search the indext in inOrder.
    index++; // increasing for future use (done after curr cuz first we need 0th element)
    Node* node = new Node(curr); // cretaes new node for every value which will come through this
    if(start == end){
        return node; //again check for end (if start == end this means we have reached the end of list)
    }

    int pos = search(inOrder, start, end, curr); //searching the position of the value of which left side is left of root and right is right side
    node->left = buildTree(preOrder,inOrder,start,pos-1); // left side of pos will be from start to pos-1
    node->right = buildTree(preOrder, inOrder, pos+1, end); // right side of pos will be from pos+1 to end
    return node;
}

int main()
{
    // vector<int> preOrder {1,2,4,3,5};
    // vector<int>inOrder {4,2,1,5,3};
    vector<int> preOrder{-11};
    vector<int> inOrder{-11};
    int n = preOrder.size();
    Node* root = buildTree(preOrder, inOrder, 0, n-1);
    inOrderPrint(root);
    cout<<endl;
}