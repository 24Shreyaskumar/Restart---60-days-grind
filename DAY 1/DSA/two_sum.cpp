/*
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.


Example 1

Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]

Explanation:
nums[0] + nums[1] = 1 + 6 = 7


Example 2

Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]

Explanation:
nums[1] + nums[5] = 3 + (-3) = 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (mp.count(target - nums[i]))
                return {mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};