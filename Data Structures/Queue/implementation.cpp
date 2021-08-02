#include<iostream>
using namespace std;
#define n 100
class queue{
    int front;
    int back;
    int *arr;

    public:
    queue(){
        front = -1;
        back = -1;
        arr = new int[n];
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue Full"<<endl;
            return;
        }
        else if(back == -1 && front == -1){
            arr[++back]=x;
            front = back;
        }
        else{
            arr[++back]=x;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"No Value"<<endl;
            return;
        }
        else ++front;
    }

    int peek(){
        if(front != -1) return arr[front];
        return -1;
    }

    bool empty(){
        if((front == -1 && back == -1) || front>back) return true;
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

    cout<<"First val "<<q.peek()<<endl;
    q.pop();
    cout<<"First val after popping " <<q.peek()<<endl;
    cout<<"isEmpty? "<<q.empty()<<endl;
}