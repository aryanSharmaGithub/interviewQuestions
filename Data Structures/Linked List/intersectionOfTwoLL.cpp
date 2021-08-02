#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data = val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtNode(node* &head, int val)
{
    node* n=new node(val);
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
    n->prev=temp;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    node* head=NULL;
    insertAtNode(head,1);
    insertAtNode(head,2);
    insertAtNode(head,3);
    insertAtNode(head,4);
    insertAtNode(head,5);
    insertAtNode(head,6);

    node* head2=NULL;
    insertAtNode(head2,0);
    insertAtNode(head2,7);
    insertAtNode(head2,1);
    insertAtNode(head2,10);
    display(head);
}