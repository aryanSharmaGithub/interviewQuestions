#include<bits/stdc++.h>
using namespace std;

bool validNumber(string A){
    int i=0,n=A.length()-1,dec=0,e=0;
    // dec and e keeps count of decimal point and exponential ‘e’
    
    // removing leading and trailing spaces
    while (A[n]==' ') n--;
    while (A[i]==' ') i++;
    // checking for empty string and string consisting only of whitespace characters
    if (i>n) return 0;
    
    // first character could be sign but 
    // if it was the only character in the string (apart from whitespaces) we return 0
    if (A[i]=='+'||A[i]=='-') {
        if (i==A.length()-1 || A[i+1]==' ') {return 0;}
        i++;
    }
    
    for (;i<=n;i++){
        // there should be only one decimal point, no exponential character before d.p.
        // the string should not end with a decimal point
        if (A[i]=='.'){
            if (dec||e||i+1>n) return 0;
            else dec=1;
        }
        
        // there should be only one exponent with atleast one digit before and after it
        // the string should not end with an exponent
        else if (A[i]=='e'){
            if (e || (i==0) || (A[i-1]<'0'||A[i-1]>'9') || i+1>n) return 0;
            else e=1;
        }
        
        // if sign character is encountered, then it must have exponent just before it and a digit just after it
        else if (A[i]=='+'||A[i]=='-') {
            if (A[i-1]!='e'||i+1>n||(A[i+1]<'0'||A[i+1]>'9'))
                return 0;
        }
        
        // if the character is not a digit, not an exponent, not a sign character, not a d.p., we return 0
        else if (A[i]<'0'||A[i]>'9') return 0;
    }
    return 1;
}

int main()
{
    string s = "4985723405.94  ";
    cout<<validNumber(s)<<endl;
}