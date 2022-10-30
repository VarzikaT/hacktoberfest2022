// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// Approch 1️⃣ - Brute Force ✅
// helper func to remove spaces from start of string
void trimStart(string &s)
{
    // trimming the string for spaces at beginning
    for (int i = 0; i < s.size();)
    {
        if (s[i] == ' ')
            s.erase(s.begin());
        else
            break;
    }
}
// helper func to remove spaces from end of string
void trimEnd(string &s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s.erase(s.end() - 1);
        }

        else
            break;
    }
}
string reverseWords(string s)
{

    // If you dont want to use vector , use a stack to store each word.
    // then you need not reverse the vector later on.
    vector<string> v;

    // trimming the spaces from front
    trimStart(s);
    // trimming the spaces from end
    trimEnd(s);

    string str = "";

    // iterating over the string
    for (int i = 0; i < s.size(); i++)
    {
        // if we encounter a space in string we have a word
        if (s[i] == ' ')
        {
            // this check avoids spaces b/w words to be pushed into the vector
            if (str.size() > 0)
            {
                // store separated words in vector
                v.push_back(str);
                // initialize str string to empty string
                str = string();
            }
        }

        // else concatenate the alphabets to make a word
        else
        {
            str = str + s[i];
        }
    }
    // pushing the last word into the vector
    v.push_back(str);

    // reversing the vector
    reverse(v.begin(), v.end());

    str = "";
    // concatenating and creating the new reversed string
    for (auto &i : v)
    {
        str += " " + i;
    }
    // first place is always a space - extra
    str.erase(str.begin());
    return str;
}

// -----------------------------------------------------------------------------------------
// Approach 2️⃣ 🔥
// Use string stream and push every seperate word into vector , reverse vector and conactenate and return it.
string reverseWords(string s)
{
    vector<string> vec;
    stringstream str(s);
    string word;
    while (str >> word) // store separated words in vector
        vec.push_back(word);

    reverse(vec.begin(), vec.end()); // reverse vector

    string res;
    for (const auto &it : vec) // concatenate strings
        res += " " + it;
    res.erase(0, 1); // first place is always a space - extra

    return res;
}

int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s);
    return 0;
}