#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool areKAnagrams(string &s1, string &s2, int k)
    {
        // code here
        int n = s1.size();
        if (n != s2.size())
            return false;

        vector<int> a1(26, 0), a2(26, 0);

        for (int i = 0; i < n; i++)
        {
            a1[s1[i] - 'a']++;
            a2[s2[i] - 'a']++;
        }

        int diff = 0;

        for (int i = 0; i < 26; i++)
        {
            diff += (a1[i] > a2[i]) ? a1[i] - a2[i] : 0;
        }

        return diff <= k;
    }
};