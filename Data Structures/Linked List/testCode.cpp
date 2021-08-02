#include<iostream>
#include<vector>
using namespace std;

// vector<int> sortedSquares(vector<int>& nums) {
//         vector <int>values;
//         vector<int> ans;
//         int max=*max_element(nums.begin(),nums.end());
//         for(int i=0;i<max+1;i++)
//         {
//             values.push_back(-10001);
//         }
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums.at(i)<0)
//             {
//                 nums.at(i)*=-1;
//                 values.at(nums.at(i))=nums.at(i);
//             }    
//             else values.at(nums.at(i))=nums.at(i);
//         }
//         for(int i=0,j=0;i<values.size();i++)
//         {
//             if(values.at(i)!=-10001)
//             {
//                 ans.push_back(values.at(i)*values.at(i));
//             }
//         }
//         for(int i=0;i<ans.size();i++)
//         {
//             cout<<ans.at(i)<<" ";
//         }
//         cout<<endl;
//         return ans;
        
//     }

// int main()
// {
//     vector <int> v;
//     v.push_back(-4);
//     v.push_back(-1);
//     v.push_back(0);
//     v.push_back(3);
//     v.push_back(10);
//     sortedSquares(v);
// }

//************************************** New Question Starts from here **********************

class node{
    public:
    int val;
    node* next;
    node(int data)
    {
        val=data;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val) /*head is required because we will need to traverse something till last so that we can insert the value at tail.*/
{
    node* n= new node(val);
    //what if the head is null, to check this, we will check the condition
    if(head==NULL)
    {
        head=n; //head will be pointing to the new node, hence it will be the starting node
        return;
    }
    node* temp = head; //temp variable so that we can traverse till last
    while(temp->next!=NULL) // temp->next means the next value stored in node temp
    {
        temp=temp->next;
    }
    //after loop is finished, temp is on the last node (where we need to insert the value)
    temp->next=n;
    // n->next=NULL; is redundant because node function (line 10) already has next as null
}

    node *getIntersectionNode(node *l1, node *l2) {
        if(l1==NULL || l2==NULL){
            return NULL;
        }
        
        while(l1 && l2){
            if(l1->val==l2->val){
                return l1;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return NULL;
    }

void displayList(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<head->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head1 = NULL; 
    insertAtTail(head1,4);
    insertAtTail(head1,1);
    insertAtTail(head1,8);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    node *head2 = NULL;
    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,1);
    insertAtTail(head2,8);
    insertAtTail(head2,4);
    insertAtTail(head2,5);

    node *head3 = getIntersectionNode(head1,head2);
    // insertAtTail(head,7);

    displayList(head3);
}