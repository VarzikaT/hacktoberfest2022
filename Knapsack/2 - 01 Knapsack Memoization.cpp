#include <bits/stdc++.h>
using namespace std;

// matrix to store result of every possible size and capacity.
int t[10][10];
//------------- 01 Knapsack Memoization-----------------

int maxProfit(vector<int> wt, vector<int> val, int capacity, int size)
{
    // base condition .
    // Think of smallest valid input for the problem
    if (capacity == 0 || size == 0)
        return 0;

    // if our matrix has value at t[size],[capacity] return that , need not to do any recursive calls for that.
    if(t[size][capacity] != -1)
        return t[size][capacity];

    /*
    There are two conditions for any weight to be put into the knapsack. 
    1 - if weight is smaller or equal to capapcity 
        -> we can put that in knapsack to maximise profit
        -> or we decide not to put it .

    2 - if weight is more than capacity , we have to skip that weight
    
    */

    //If weight is smaller or equal to the capacity of knapsack
    if (wt[size - 1] <= capacity)
    {
        // return max of both if we include the weight or we dont include it .
        return t[size][capacity] = max(val[size - 1] + maxProfit(wt, val, capacity - wt[size - 1], size - 1),
                   maxProfit(wt, val, capacity, size - 1));
    }
    // weight is more than capacity so we skip that weight.
    else
        return t[size][capacity] = maxProfit(wt, val, capacity, size - 1);
}

int main()
{
    // initializing matrix with -1 
    memset(t, -1 , sizeof(t));

    vector<int> wt = {1, 8, 4, 6, 2};
    vector<int> val = {1, 4, 5, 7, 8};
    int capacity = 10;

    cout <<"Max Profit : "<<maxProfit(wt, val, capacity, wt.size());

    return 0;
}
