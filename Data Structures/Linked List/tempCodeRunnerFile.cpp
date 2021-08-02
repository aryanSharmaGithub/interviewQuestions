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


node* addTwoNumbers(node* l1, node* l2) {
        node *temp1=l1,*temp2=l2;
        node *ans = NULL;
        int add=0;
        int value=0;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1==NULL && temp2!=NULL)
            {
                if(temp2->data+add>9)
                {       
                    value=(temp2->data+add)%10;
                    add=(temp2->data+add)/10;
                    if(temp2->next==NULL)
                    {
                        insertAtTail(ans,value);
                        insertAtTail(ans,add);
                        return ans;
                    }
                    else
                    insertAtTail(ans,value);
                }
                else
                    {
                        insertAtTail(ans,temp2->data+add);
                        add=0;
                    }
                
                temp2=temp2->next;
            }
            else if(temp1!=NULL && temp2==NULL)
            {
                if(temp1->data+add>9)
                {
                    value=(temp1->data+add)%10;
                    add=(temp1->data+add)/10;
                    if(temp1->next==NULL)
                    {
                        insertAtTail(ans,value);
                        insertAtTail(ans,add);
                        return ans;
                    }
                    else
                    insertAtTail(ans,value);
                }
                else
                    {
                        insertAtTail(ans,temp1->data+add);
                        add=0;
                    }
                temp1=temp1->next;
            }
            else
            {
                if(temp1->data+temp2->data+add>9)
                {
                    value=(temp1->data+add+temp2->data)%10;
                    add=(temp1->data+add+temp2->data)/10;
                    if(temp1->next==NULL || temp2->next==NULL)
                    {
                        insertAtTail(ans,value);
                        // insertAtTail(ans,add);
                    }
                    else
                    insertAtTail(ans,value);
                }
                else
                    {
                        insertAtTail(ans,temp1->data+add+temp2->data);
                        add=0;
                    }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return ans;
    }

int main()
{
    node* head1=NULL;
    insertAtTail(head1,8);
    insertAtTail(head1,3);
    insertAtTail(head1,2);
    // insertAtTail(head1,9);
    // insertAtTail(head1,9);
    // insertAtTail(head1,9);
    // insertAtTail(head1,9);

    node* head2=NULL;
    insertAtTail(head2,9);
    insertAtTail(head2,2);
    insertAtTail(head2,1);
    // insertAtTail(head2,9);


// [8,3,2]
// [9,2,1]
    
    node* head3 = addTwoNumbers(head1,head2);
    display(head3);

}