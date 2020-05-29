/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 *
 * https://leetcode-cn.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (46.11%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 18.3K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * 在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。
 * 
 * 例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
 * 
 * 我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。
 * 
 * 最终结果按照字典顺序输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abbxxxxzzy"
 * 输出: [[3,6]]
 * 解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abc"
 * 输出: []
 * 解释: "a","b" 和 "c" 均不是符合要求的较大分组。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcdddeeeeaabbbcd"
 * 输出: [[3,5],[6,9],[12,14]]
 * 
 * 说明:  1 <= S.length <= 1000
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if (S.empty()) {
            return vector<vector<int>> ();
        }
        vector<vector<int>> res;
        int first = 0;
        for (int i = 0; i < S.size(); ) {
            while (i < S.size() && S[i] == S[first]) {
                i += 1;
            }
            if (i - first >= 3) {
                res.push_back(vector<int>({first, i - 1}));
            }
            first = i;
        }
        return res;
    }
};

// @lc code=end

