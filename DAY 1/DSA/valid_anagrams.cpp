/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
Answer to the follow up question - we can directly maintain an unoredered map and then keep track of the frequency of each characted in both the strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;

        vector<int> frq1(26, 0), frq2(26, 0);
        
        for (int i = 0; i < n; i++) {
            frq1[s[i]-'a']++;
            frq2[t[i]-'a']++;
        }

        return frq1 == frq2;
    }   
};