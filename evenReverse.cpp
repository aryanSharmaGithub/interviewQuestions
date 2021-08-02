#include<iostream>
#include<insert_search_LL.hpp>

node *reverse(node *head){
    node *curr = head, *prev = NULL, *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

node *merge(node *l1, node *l2){
    node *dummy = new node(0);
    node *temp = dummy;
    while(l1 && l2){
        temp->next = new node(l1->data);
        temp = temp->next;
        
        temp->next = new node(l2->data);
        temp = temp->next;
        
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1){
        temp->next = new node(l1->data);
        l1 = l1->next;
        temp = temp->next;
    }
    if(l2){
        temp->next = new node(l2->data);
        temp = temp->next;
        l2 = l2->next;
    }
    return dummy->next;
}

node* solve(node* A) {
    int count = 0;
    node *temp = A;
    node *even = new node(0);
    node *tempEven = even;
    node *odd = new node(0);
    node *tempOdd = odd;
    while(temp){
        if(count%2!=0){
            tempEven->next = new node(temp->data);
            tempEven = tempEven->next;
        }else{
            tempOdd->next = new node(temp->data);
            tempOdd = tempOdd->next;
        }
        temp = temp->next;
        count++;
    }
    even = reverse(even->next);
    odd = odd->next;
    return merge(odd,even);
}

int main()
{
    node *l1 = NULL;
    insertAtTail(l1,1);
    insertAtTail(l1,2);
    insertAtTail(l1,3);
    insertAtTail(l1,4);
    node *l2 = solve(l1);
    display(l2);
}
