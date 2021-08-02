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

node *reverseKNodes(node *head, int k){
    node *prev = NULL;
    node *curr = head;
    node *next;
    int count = 0;
    while(curr && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        head->next = reverseKNodes(next,k);
    }
    return prev;
}

int main()
{
    node *head = NULL;
    // for(int i=1;i<11;i++){
    //     insertAtNode(head,i);
    // }
    insertAtNode(head,1);
    insertAtNode(head,2);
    insertAtNode(head,3);
    insertAtNode(head,4);
    insertAtNode(head,5);
    // insertAtNode(head,6);
    // insertAtNode(head,7);
    // insertAtNode(head,8);
    // insertAtNode(head,9);
        
    node *head2 =  reverseKNodes(head,3);
    display(head2);
}