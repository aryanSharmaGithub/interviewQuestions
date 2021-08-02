#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL) //Because if the list in empty, how can it point to prev. 
    {
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;
    if(head==NULL)
    {
        // head=n;
        // return;
        // or (the way we will do it)
        insertAtHead(head,val);
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

void deleteNodeByPos(node* &head,int pos)
{
    node* temp=head;

    if(pos==1) //If we need to delete the head node
    {
        head=head->next; //Move head to the next node
        head->prev=NULL; //Head prev is always NULL
        delete temp; //We are on head node only (now the new head is the second node) and we can directly delete it
        return; // bye bye
    }
    int count=1; //For position
    while(temp!=NULL && count!=pos) //We will go to the node which is to deleted
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next; // 1<->2<->3. temp(2)'s prev(1)'s next(1->) = temp(2)'s next(3). i.e. 1->3
    if(temp->next!=NULL) //Because this will cause error if we will delete last node.
    temp->next->prev=temp->prev; // same. temp(2)'s next(3)'s prev(<-3) =temp(2)'s prev(1). i.e. 1<-3.
    //that means, 1<->3
    
    delete temp; //No need of making pointer in this because we are already on our desired node and temp is useless now.
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
    display(head);
    insertAtHead(head,0);
    display(head);
    deleteNodeByPos(head,1);
    display(head);
    deleteNodeByPos(head,6);
    display(head);
}