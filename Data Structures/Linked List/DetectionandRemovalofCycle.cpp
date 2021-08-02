#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

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

void makeCycle(node* &head, int pos) // Makes the cycle (dont think this is that important to understand)
{
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectCycle(node* &head) //This is used to detect cycle (Warshell Algo)
{
    /* We will take two pointers, one fast and one slow (one will go one step and one goes 2 steps)
       and then will run it till fast one does not come to null or its next is not null. If fast is
       equal to slow in the while loop, return true (cycle detected as they both colided) */
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        return true;
    }
    return false;
}

void removeCycle(node* &head)
{
    /* We will detect the cycle again, once the cycle is detected, we will point the fast one to start
       and then proceed both the pointers on by one until the next of both do not point to the same node.
       After that, do slow->next=NULL breaking the cycle */
    node* slow=head;
    node* fast=head;
    do
    {
        fast=fast->next->next;
        slow=slow->next;        
    } while (fast!=slow);
    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    makeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    display(head);
}