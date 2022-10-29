#include <bits/stdc++.h>
using namespace std;

//----------------- 01 Knapsack Recursive-----------------

int maxProfit(vector<int> wt, vector<int> val, int capacity, int size)
{
    // base condition .
    // Think of smallest valid input for the problem
    if (capacity == 0 || size == 0)
        return 0;

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
        return max(val[size - 1] + maxProfit(wt, val, capacity - wt[size - 1], size - 1),
                   maxProfit(wt, val, capacity, size - 1));
    }
    // weight is more than capacity so we skip that weight.
    else
        return maxProfit(wt, val, capacity, size - 1);
}

int main()
{
    vector<int> wt = {1, 8, 4, 6, 2};
    vector<int> val = {1, 4, 5, 7, 8};
    int capacity = 10;

    cout <<"Max Profit : "<<maxProfit(wt, val, capacity, wt.size());

    return 0;
}
