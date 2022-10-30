// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

/*
    Brute Force - Generate all possible parenthesis and then check for valid parenthesis in them.

    Better Approach - For any value of n , if we want balanced parenthesis it should have same no of opening and closing brackets and max length of any valid parenthesis would be 2 * n ;

    therefore we keep a track of number of opening and closing brackets.
    and one more thing that first bracket can't be a closing bracket. 
    and at any instance for every opening bracket there would be a closing bracket after it only.
    thats why we put ( close > open ) condition .     
*/
void generate(vector<string> &ans, string str, int n, int open, int close)
{
    // if we made a string equal to 2*n length. push our string into ans vector.
    if (str.length() == 2 * n)
    {
        ans.push_back(str);
        return;
    }

    // if we have opening brackets then use it for making parenthesis
    if (open > 0)
        generate(ans, str + "(", n, open - 1, close);

    //the condition (close > open) checks that , for every opening bracket there would be a closing bracket after it only .
    if (close > 0 && close > open)
        generate(ans, str + ")", n, open, close - 1);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    generate(ans, "", n, n, n);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(2);

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    return 0;
}