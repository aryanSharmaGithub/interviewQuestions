#include<iostream>
#include<vector>
using namespace std;
int maxProfit1(vector<int>& prices) {
        int min=99999;
        int max=-99999;
        //vector <int> min(100000,-1);
        int n=-1;
        int j=-1;
        if(prices.size()==1)
            return 0;
        for(int i=0;i<prices.size();i++) //Find Minimum Value
        {
            if(i==prices.size()-1)
            continue;
            if(prices[i]<min)
            {
                min=prices[i];
                n=i;
            }
        }

        for(int i=n;i<prices.size();i++)
        {
            if(prices[i]>max)
            {
                max=prices[i];
                j=i;
            }
        }
        int difference=prices[j]-prices[n];
        if(difference<0)
            return 0;
        else
            return difference;
    }
int maxProfit(vector<int>& prices)
{
    int maxDiff=0;
    int lowestStock=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]<lowestStock)
        lowestStock=prices[i];
        if(prices[i]>lowestStock)
        {
            if(maxDiff<(prices[i]-lowestStock))
            maxDiff=prices[i]-lowestStock;
        }
    }
    return maxDiff;
}
int main()
{
    vector <int> prices;
    prices.push_back(7);
    prices.push_back(2);
    prices.push_back(9);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    cout<<maxProfit(prices);

}