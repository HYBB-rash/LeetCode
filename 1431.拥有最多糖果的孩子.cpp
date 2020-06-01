/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
// #include <vector>
// #include <algorithm>
// using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto it = max_element(candies.begin(), candies.end());
        int max_cand = *it;
        vector<bool> ans(candies.size());
        for (int i = 0; i < candies.size(); i++)
            ans[i] = candies[i] + extraCandies >= max_cand;
        return ans;
    }
};
// @lc code=end

