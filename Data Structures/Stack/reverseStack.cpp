#include<bits/stdc++.h>
using namespace std;

void reverseAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    reverseAtBottom(st,ele);

    st.push(topele);
}

void reverseStack(stack<int> &st){
    if(st.empty()) return;
    int ele = st.top();
    st.pop();
    reverseStack(st);
    reverseAtBottom(st,ele);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    int i=0;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}