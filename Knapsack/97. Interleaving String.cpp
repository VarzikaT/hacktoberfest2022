// 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/

#include <bits/stdc++.h>
using namespace std;

/*  Approach 1️⃣- Recursion - TLE ❌
    Time - O(2^ M+N)  Space - O(M+N)
*/

bool recursive(string s1, string s2, string s3, int l1, int l2, int l3, int P1, int P2, int P3)
{
  // base case , if we completely parse s3 , check if we have completely used s1 and as well as s2 and return true , if not return false
  if (l3 == P3)
  {
    if (l1 == P1 && l2 == P2)
      return true;
    return false;
  }

  // if s1 empties first we check for matching char from s2 else return false;
  if (P1 == l1)
  {
    if (s2[P2] == s3[P3])
    {
      return recursive(s1, s2, s3, l1, l2, l3, P1, P2 + 1, P3 + 1);
    }
    return false;
  }

  // similarly if s2 empties first we check for matching char from s1 else return false;
  if (P2 == l2)
  {
    if (s1[P1] == s3[P3])
    {
      return recursive(s1, s2, s3, l1, l2, l3, P1 + 1, P2, P3 + 1);
    }
    return false;
  }

  bool fromS1 = false, fromS2 = false;

  // matching char from s1
  if (s1[P1] == s3[P3])
    fromS1 = recursive(s1, s2, s3, l1, l2, l3, P1 + 1, P2, P3 + 1);

  // matching char from s2
  if (s2[P2] == s3[P3])
    fromS2 = recursive(s1, s2, s3, l1, l2, l3, P1, P2 + 1, P3 + 1);

  // return or of both results
  return fromS1 || fromS2;
}

// ------------------------------------------------------------------------------------------------
// Approach 2️⃣ - Recursion + Memoization - Top Down
// ⏱ Time - O(M+N) - count of all possible combinations (len(s1) + len(s2))

// unorderd map to store the memoized results
unordered_map<string, bool> memo;
bool memoization(string s1, string s2, string s3, int l1, int l2, int l3, int P1, int P2, int P3)
{
  // base case , if we completely parse s3 , check if we have completely used s1 and as well as s2 and return true , if not return false
  if (l3 == P3)
  {
    if (l1 == P1 && l2 == P2)
      return true;
    return false;
  }

  // generating unique key
  string key = to_string(P1) + "*" + to_string(P2) + "*" + to_string(P3);

  // find anaswer in our memo
  if (memo.find(key) != memo.end())
    return memo[key];

  // if s1 empties first we check for matching char from s2 else return false;
  if (P1 == l1)
  {
    if (s2[P2] == s3[P3])
    {
      return memo[key] = memoization(s1, s2, s3, l1, l2, l3, P1, P2 + 1, P3 + 1);
    }
    return memo[key] = false;
  }

  // similarly if s2 empties first we check for matching char from s1 else return false;
  if (P2 == l2)
  {
    if (s1[P1] == s3[P3])
    {
      return memo[key] = memoization(s1, s2, s3, l1, l2, l3, P1 + 1, P2, P3 + 1);
    }
    return memo[key] = false;
  }

  bool fromS1 = false, fromS2 = false;

  // matching char from s1
  if (s1[P1] == s3[P3])
    fromS1 = memoization(s1, s2, s3, l1, l2, l3, P1 + 1, P2, P3 + 1);

  // matching char from s2
  if (s2[P2] == s3[P3])
    fromS2 = memoization(s1, s2, s3, l1, l2, l3, P1, P2 + 1, P3 + 1);

  // return or of both results
  return memo[key] = fromS1 || fromS2;
}

bool isInterleave(string s1, string s2, string s3)
{
  int l1 = s1.size();
  int l2 = s2.size();
  int l3 = s3.size();

  return recursive(s1, s2, s3, l1, l2, l3, 0, 0, 0);
}

int main()
{
  return 0;
}