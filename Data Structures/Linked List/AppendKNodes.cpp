#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val)
    {
        data=val;
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

node* kappend(node* &head, int pos)
{
    if(pos==0) //If no change has to be made
    return head;

    node* temp=head; // Will be used as a tail
    int count=1; //count the steps to be taken from tail

    while(temp->next!=NULL) //Temp is going to the tail of LL
    {
        temp=temp->next;
    }

    temp->next=head; //Linking tail to the head (so that we can break the LL in b/w)
    head->prev=temp;

    while(temp->prev!=NULL && count<pos) // In this, even if pos>lenght of LL, it will go around till count<pos, essentially, I did a pos=pos%length.
    {
        temp=temp->prev; //Going back to the new Head node
        count++;
    }
    head=temp; //Real head going to the soon to be head node
    head->prev->next=NULL; //Head's prev (the node before it)'s next is null (meaning the node before head is now last node)
    head->prev=NULL; //Head node is made 
    return head;
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
    kappend(head,2);
    display(head);
    insertAtNode(head,7);
    insertAtNode(head,8);
    kappend(head,22);
    display(head);
    return 0;
}