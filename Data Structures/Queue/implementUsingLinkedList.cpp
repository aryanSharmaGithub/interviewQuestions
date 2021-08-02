#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node *next;
    node(int data){
        val = data;
        next = NULL;
    }
};

class queue{
    node *front;
    node *back;

    public:
    queue(){
        front = NULL;
        back = NULL;
    }

    void push(int x){
        node *n = new node(x);
        if(front == NULL){
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue Empty"<<endl;
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek(){
        if(front==NULL) return NULL;
        else return front->val;
    }

    bool empty(){
        if(front == NULL) return true;
        else return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"First element "<<q.peek()<<endl;
    q.pop();
    cout<<"After popping "<<q.peek()<<endl;
    cout<<"isEmpty? "<<q.empty()<<endl;
}