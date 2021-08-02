// WRONG ANSWER

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *arb;
    node(int val){
        data = val;
        next = NULL;
        arb = NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head; // To initialise the connection  bw first and this new node
    head=n; //Friendship with first node has ended, now new node is head's best friend (and hence, first node)
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

void display(node* head) //head because it is used as a funtion to traverse (and no reference because no change)
{
    node* temp=head;
    while(temp!=NULL) //We used temp!=NULL instead of temp->next!=NULL because that would not print the last element
    {
        cout<<temp->data<<" ";
        temp=temp->arb; //To traverse the linked list
    }
    cout<<"NULL"<<endl;
}

node *merge(node *l, node *r){
    node *dummy = new node(0);
    node *temp = dummy;
    while(l && r){
        if(l->data < r->data){
            temp->arb = l;
            l = l->arb;
        }else{
            temp->arb = r;
            r = r->arb;
        }
        temp = temp->arb;
    }

    while(l){
        temp->arb = l;
        l = l->arb;
        temp = temp->arb;
    }

    while(r){
        temp->arb = r;
        r = r->arb;
        temp = temp->arb;
    }

    return dummy->arb;
}

node *mergeSort(node *head){
    if(!head || !head->arb) return head;
    node *temp = head;
    node *fast = head;
    node *slow = head;

    while(fast && fast->next){
        temp = slow;
        slow = slow->arb;
        fast = fast->arb->arb;
    }
    temp->arb = NULL;
    node *leftSort = mergeSort(head);
    node *rightSort = mergeSort(slow);
    return merge(leftSort,rightSort);
}

node *arbsort(node* head){
    node *temp = head;
    while(temp->next){
        temp->arb = temp->next;
        temp = temp->next;
    }
    return mergeSort(head);
}

int main()
{
    node *head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,10);
    insertAtTail(head,2);
    insertAtTail(head,3);
    arbsort(head);

    display(head);
}