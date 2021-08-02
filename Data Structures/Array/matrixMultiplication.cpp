//Not Complete but doable

#include<iostream>
#include<vector>
using namespace std;

void matrixMultiplication(int A[][4],int B[][3])
{
    int tempSum=0;
    int ans[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            tempSum+=A[i][j]*B[j][i];
        }
    }
    cout<<tempSum<<endl;
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main()
{
    int A[3][4]={{2,4,1,2},{8,4,3,6},{1,7,9,5}};
    int B[4][3]={{1,2,3},{4,5,6},{7,8,9},{4,5,6}};
    matrixMultiplication(A,B);
    // vector<vector<int> > A(3,vector<int> );
    // A[0].push_back(2);
    // A[0].push_back(4);
    // A[0].push_back(1);
    // A[0].push_back(2);
    // A[1].push_back(8);
    // A[1].push_back(4);
    // A[1].push_back(3);
    // A[1].push_back(6);
    // A[2].push_back(1);
    // A[2].push_back(7);
    // A[2].push_back(9);
    // A[2].push_back(5);
    
    // vector<vector<int> > two_D_vector{
    //     { 1, 2, 3 }, //comma separated lists
    //     { 5, 6, 7 },
    //     { 8, 9, 3 }
    // };
    // vector<vector<int> > B;
    // B[0].push_back(1);
    // B[0].push_back(2);
    // B[0].push_back(3);
    // B[1].push_back(4);
    // B[1].push_back(5);
    // B[1].push_back(6);
    // B[2].push_back(7);
    // B[2].push_back(8);
    // B[2].push_back(9);
    // B[3].push_back(4);
    // B[3].push_back(5);
    // B[3].push_back(6);

    // vector<vector<int> > ans=matrixMultiplication(A,B);
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)
    //     {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // vector<vector<int> > ans=matrixMultiplication(A,B);
    // for(int i=0;i<ans.size();i++)
    // {
    //     for(int j=0;j<ans[0].size();j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}