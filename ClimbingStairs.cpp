#include<iostream>
using namespace std;
// int ways(int n)
// {
//     int stairs,i;
//     int a[2][n];
//     int steps[2]={1,2};
//     for(i=0;i<2;i++)
//     {
//         if(i==0)
//         a[i][stairs]=1;
//         for(stairs=0;stairs<n;stairs++)
//         {
//             if(stairs==0)
//                 a[i][stairs]=1;
//             if(i>stairs)
//                 a[i][stairs]=a[i-1][stairs];
//             else
//             a[i][stairs]=a[i-1][stairs]+a[i][stairs-steps[i]];
//         }
//     }
//     return a[2][n];
// }
int ways(int n)
{
    vector <int> memo[n+1]; 
    //memo = new int[n+1];
     if (n < 0) {
            return 0;
        } else if (memo[n] != 0) {
            // If we stored something in our cache reuse it and avoid
            // recalculating everything
            return memo[n];
        } else if (n == 0) {
            return 1;
        } else {
            // store our calculation inside our cache so we don't
            // have to recalculate it again for memo[n]
            memo[n] = ways(n-1) + ways(n-2);
            return memo[n];
        }
}
int main()
{
            vector <int> min ={0};

    int n=2;
    cout<<ways(n);
}