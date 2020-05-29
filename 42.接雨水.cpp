/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.29%)
 * Likes:    1000
 * Dislikes: 0
 * Total Accepted:    70.9K
 * Total Submissions: 142.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int max_ele = height[0], left_part = 0, right_part = height[0], total = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if(max_ele<height[i])
                max_ele = height[i];
            else{
                left_part += max_ele - height[i];
            }
            right_part += height[i];
        }
        total = height.size() * max_ele - right_part;
        max_ele = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if(max_ele<height[i])
                max_ele = height[i];
            else{
                left_part += max_ele - height[i];
            }
        }
        return left_part - total;
    }
};
// @lc code=end

