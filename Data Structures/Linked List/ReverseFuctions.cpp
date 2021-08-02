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

void insertAtTail(node* &head,int val)
{
    node* n=new node (val);
    node* temp=head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

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

node* reverseIteration(node* &head)
{
    node* prevPtr=NULL;
    node* currPtr=head;
    node* nextPtr;

    while(currPtr!=NULL)
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    return prevPtr;
}

node* reverseRecursive(node* &head2)
{
    if(head2==NULL || head2->next==NULL)
    return head2;
    node* newhead=reverseRecursive(head2->next);
    head2->next->next=head2;
    head2->next=NULL;
    return newhead;
}

node* reverseK(node* &head, int k)
{
    node* curr=head;
    node* prev=NULL;
    node* nextptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    head->next=reverseK(nextptr,k);
    return prev;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    // insertAtTail(head,6);
    display(head);
    node* head2=reverseIteration(head);
    display(head2);
    node* head3=reverseRecursive(head2);
    display(head3);
    node* head4=reverseK(head3,3);
    display(head4);
    return 0;
}