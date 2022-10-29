#include <bits/stdc++.h>
using namespace std;

// matrix to store result of every possible size and capacity.
int t[10][10];

//------------- 01 Knapsack Bottom UP DP-----------------

int maxProfit(vector<int> wt, vector<int> val, int capacity, int size)
{
    int n = wt.size();
    
    // initialization for matrix
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1 ; i < n+1; i++)
    {
        for (int j = 1; j < capacity+1; j++)
        {   
            // calculating max profit at (i , j) , 
            // if weight is smaller or equal to knapsack capacity 
            if(wt[i-1] <= j)
                t[i][j] = max( val[i-1] + t[i-1][j - wt[i-1]]  , t[i-1][j]);

            else 
                t[i][j] = t[i-1][j];    
        }
        
    }

    return t[n][capacity];

}

int main()
{
    // initializing matrix with -1
    memset(t, -1, sizeof(t));

    vector<int> wt = {1, 8, 4, 6, 2};
    vector<int> val = {1, 4, 5, 7, 8};
    int capacity = 10;

    cout << "Max Profit : " << maxProfit(wt, val, capacity, wt.size());

    return 0;
}