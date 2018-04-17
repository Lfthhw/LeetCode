#include <bits/stdc++.h>
using namespace std;

/**
 * Description:
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].

 * Note: The returned array must be malloced, assume caller calls free().
 */


class Solution {
public:
    /**
     * Solution:
     * use map to record number index
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int x;
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            x = nums[i];
            if (mp[target - x]) {
                v.push_back(mp[target - x] - 1);
                v.push_back(i);
                return v;
            }
            mp[x] = i + 1;
        }
        return v;
    }
};

int main ()  {
    int num[10] = {0,1,2,4,-8,-20,10};
    int target = -10;
    vector<int> v(num, num + 7);
    vector<int> ans;
    Solution a;
    ans = a.twoSum(v, target);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
