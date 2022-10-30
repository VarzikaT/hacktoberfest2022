// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;

    if (intervals.size() == 0)
        return mergedIntervals;

    // Sort the vector so that overlapping intervals are adjacent to each other
    sort(intervals.begin(), intervals.end());

    // put first interval in tempInterval
    vector<int> tempInterval = intervals[0];

    for (auto each : intervals)
    {
        // check if intervals are merging or not
        if (each[0] <= tempInterval[1])
        {
            tempInterval[1] = max(each[1], tempInterval[1]);
        }
        // if intervals are not merging simply push_back interval , and reassign value interval to temp_Interval
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval = each;
        }
    }
    // Completetd the iteration for all intervals then simply push_back last interval
    mergedIntervals.push_back(tempInterval);

    return mergedIntervals;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> mergedIntervals = merge(intervals);

    for (vector<int> each : mergedIntervals)
    {
        for (int elem : each)
            cout << elem << endl;
    }
    return 0;
}