#include<iostream>
#include<vector>
using namespace std;

void sieveOfEratosthenes(int n)
{
    // To check what is true (true means prime number)
    vector<int> ansCheck(n+1,1);

    // Start from 2 because 0 1 aint real :P
    // p*p because if we notice, any number will be decided prime or not after it reaches its square
    // This is because any number before p will have had its turn and would have cancelled its factors (all prime numbers before p)
    // For eg. if i=5, then 5*2,5*3,5*4 have been factored out by 2 and 3.
    for(int p=2;p<=sqrt(n);p++)
    {
        // This means that starting is true(i.e. 2 and 3 are true so we will go inside to make their factors false)
        if(ansCheck[p]==1)
        {
            // Same logic to declare i=p*p as above. We traverse by i+=p so that we can false out every factor of p
            for(int i=p*p; i<n+1 ; i+=p)
            {
                // making every factor false;
                ansCheck[i]=0;
            }
        }
    }

    vector<int> spf;

    for(int i=2;i<n+1;i++)
    {
        if(ansCheck[i]==1)
        {
            spf.push_back(i);
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void primeFactorisation(int n)
{
    int checkArr[n+1];
    for(int i=2;i<n+1;i++)
    {
        checkArr[i]=i;
    }

    for(int p=2;p*p<n+1;p++)
    {
        if(checkArr[p]==p)
        {
            for(int i=p*p;i<n+1;i+=p)
            {
                checkArr[i]=i;
            }
        }
    }
}

int main()
{
    int n=9000;
    sieveOfEratosthenes(n);

}