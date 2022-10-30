#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterELement(vector<int> nums)
{
    vector<int> nge(nums.size(), -1);
    stack<int> st;

    st.push(nums[nums.size() - 1]);
    nge[nums.size() - 1] = -1;

    for (int i = nums.size() - 2; i >= 0; i--)
    {

        // if stack is non empty and our current element is greater than top of stack , we need to pop those elements
        // we need to pop out smaller values than current bcoz we have a greater value so the smaller values after this would not contribute in finding next greater element .
        while (st.size() > 0 && nums[i] >= st.top())
        {
            // pop elements till our top becomes greater than curr
            // or stack becomes empty (i.e no next greater element)
            st.pop();
        }

        // if stack is empty , that means there's no greater element on right of it so put -1 .
        if (st.size() == 0)
            nge[i] = -1;

        // else put the topmost element of stack as it is the next greater element to right .
        else
        {
            nge[i] = st.top();
        }

        // push the current element in stack
        st.push(nums[i]);
    }

    return nge;
}

int main()
{
    vector<int> nums = {2, 7, 4, 3, 5, 1};
    vector<int> ans = nextGreaterELement(nums);

    for (auto &each : ans)
        cout << each << " ";
    return 0;
}
