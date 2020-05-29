/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.01%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 36.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 * 
 * 两个相邻元素间的距离为 1 。
 * 
 * 示例 1: 
 * 输入:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 输出:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 示例 2: 
 * 输入:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * 
 * 输出:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵的元素个数不超过 10000。
 * 给定矩阵中至少有一个元素是 0。
 * 矩阵中的元素只在四个方向上相邻: 上、下、左、右。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans(matrix.size());
        queue<pair<int, int>> list;
        pair<int, int> Temp;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); i++)
            {
                if (matrix[i][j] == 0)
                {
                    Temp.first = i, Temp.second = j;
                    list.push(Temp);
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
            ans[i].resize(matrix[0].size());
        int size = 0, cnt = 1;
        while (!list.empty())
        {
            size = list.size();
            while (size--)
            {
                Temp = list.front();
                list.pop();
                int x = Temp.first, y = Temp.second;
                for (int i = 0; i < 4; i++)
                {
                    int X = x + dx[i], Y = y + dy[i];
                    if (X >= 0 && Y >= 0 && X < matrix.size() && Y < matrix[0].size())
                    {
                        if (matrix[X][Y] == 1 && ans[X][Y] == 0)
                        {
                            ans[X][Y] = cnt;
                            Temp.first = X, Temp.second = Y;
                            list.push(Temp);
                        }
                    }
                }
                cnt++;
            }
        }
        return ans;
    }
};
// @lc code=end
