// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char &ch : s)
    {
        switch (ch)
        {
        case '(':

        case '{':

        case '[':
            st.push(ch);
            break;

        case ')':
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
            break;

        case '}':
            if (st.empty() || st.top() != '{')
                return false;
            else
                st.pop();
            break;

        case ']':
            if (st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
            break;

        default:;
        }
    }
    return st.empty();
}

int main()
{
    string s = "(){}[]";
    cout << isValid(s);
    return 0;
}