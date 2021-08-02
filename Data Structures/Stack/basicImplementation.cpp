#include<iostream>
using namespace std;
#define n 100

class stack{
    int top;
    int *arr;

    public:
    stack(){
        arr = new int[n];
        top=-1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"Stack Overflow";
            return;
        }
        else arr[++top]=x;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow";
            return;
        }
        --top;
    }

    void Top(){
        if(top==-1) {cout<<"No element";return;}
        return arr[top];
    }

    bool empty(){
        if(top==-1) return true;
        else return false;
    }

}

int main(){
    stack s;
    s.push(1);
    
}