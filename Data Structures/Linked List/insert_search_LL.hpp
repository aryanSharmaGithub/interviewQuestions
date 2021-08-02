#include<iostream>
using namespace std;

class node{
    public:
            int data;
            node* next; 
            //Node* is pointer of type node
            //(because we will need to point to next node and that node will be of type node).
            node (int val)
            {
                data = val;
                next = NULL;
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

bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return true;
        temp=temp->next;
    }
    return false;
}

void display(node* head) //head because it is used as a funtion to traverse (and no reference because no change)
{
    node* temp=head;
    while(temp!=NULL) //We used temp!=NULL instead of temp->next!=NULL because that would not print the last element
    {
        cout<<temp->data<<" ";
        temp=temp->next; //To traverse the linked list
    }
    cout<<"NULL"<<endl;
}

void deleteNode(node* &head,int val)
{
    node* temp=head;
    if(temp->data==val) //If we need to delete first node
    {
        node* toDelete = head; //Create another pointer to delete
        head=head->next; //Point the OG head to second node (which will be first eventually)
        delete toDelete; //Delete First node
        return; // Be happy
    }
    if(temp->next==NULL) //If only one element is present in LL
    {
        head=NULL;
        return;
    }
    if(head==NULL) //If we used this function on an empty list
    {
        return;
    }
    while(temp->next->data!=val) //means the the value of the next value from temp should be the same (basically one before the node which is to be deleted)
    {
        temp=temp->next;
    }
    node* toDelete=temp->next; //To free up the node (to free up space, no space occupying)
    temp->next=temp->next->next; //Making new connection with the next LL (1->2->3 is now 1->3. Refer notes for more details)
    delete toDelete; //Free up the space
}

node* reversePtrIterative(node* &head) //node* is used because we need to return the whole LL and the LL is in node type
{
    node* prevPtr = NULL; // Prev pointer will be before the LL (see diag for reference)
    node* currPtr = head; // Starting of the list
    node* nextPtr; // Will declare in loop
    while(currPtr!=NULL) //Because we need to change the link of last element also
    {
        //See diag for reference
        nextPtr=currPtr->next; 
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    return prevPtr; //because it is the new head now (as it is on the last element, which is now the first)
} 

node* reversePtrRecursive(node* &newhead) //Took newhead (Already reversed list) to make it the OG LL
{
    if(newhead==NULL || newhead->next==NULL) //Base case (if the LL is only of one element or we got to the last element)
    {
        return newhead;
    }
    node* newheadrec=reversePtrRecursive(newhead->next); //Recursively go to the last element
    newhead->next->next=newhead; // If we have 1->2<-3<-4 (due to recursion), then 1's next (2) next (that is to decide) will be head (i.e. 1, link change)
    newhead->next=NULL; //Head will point to NULL (successfully transformed to last element)
    return newheadrec; //This will be from the last element (which is now the first)
}

node* reverseK(node* &head,int k) //Reverse Normally bass count the number of time it is being reversed
{
    node* prev=NULL;
    node* next;
    node* current=head;
    int count=0; //To count how many time it is reversed at a time
    while(current!=NULL && count<k) //Both should satisfy
    {
        //Same as iterative reverse (only this time the counts are specific)
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL) //Check if we have reached the end of string
    head->next=reverseK(next,k); // head is the last reversed element in first reversal (like if k=2, then in 1 and 2, head will be 2)
    return prev; //because new head will be prev
}

// int main()
// {
//     node* head = NULL; 
//     /* Need to do this so that we can give value at insertion. When we give value NULL, the first node
//        condition will rise up and then it will change the head to the first node (the reason why we chose
//        to pass head with reference, so that we can change the value of head). */
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     insertAtHead(head,0);
//     display(head);
//     node* newhead=reversePtrIterative(head); //New head for the reversed LL 
//     display(newhead);
//     node* newheadRec=reversePtrRecursive(newhead); //New head for the again reversed LL
//     display(newheadRec);
//     node* newheadreverse=reverseK(head,2);
//     display(newheadreverse);
//     return 0;
// }