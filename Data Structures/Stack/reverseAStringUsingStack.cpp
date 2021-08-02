#include<iostream>
#include<stack>
using namespace std;

void reverseString(string s){
    stack<string> rev;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i++];
        }
        rev.push(word);
    }
    while(!rev.empty()){
        cout<<rev.top()<<" ";
        rev.pop();
    }
    cout<<endl;
}

int main()
{
    string s= "What have you done in your life?";
    reverseString(s);
}