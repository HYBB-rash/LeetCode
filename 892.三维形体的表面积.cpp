/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (55.95%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 11.5K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 * 
 * 请你返回最终形体的表面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    int surfaceArea(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]) area+=grid[i][j]*4+2;
                for(int k=0;k<4;k++){
                    if(i+x[k]>=0&&i+x[k]<grid.size()){
                        if(j+y[k]>=0&&j+y[k]<grid[i].size()){
                            if(grid[i+x[k]][j+y[k]]>grid[i][j]) area-=grid[i][j];
                            else area-=grid[i+x[k]][j+y[k]];
                        }
                    }
                }
            }
        }
        return area;
    }
};
// @lc code=end

