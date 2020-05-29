/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (38.61%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 21.7K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 * 
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 * 
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释： 
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释： 
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    int maxDistance(vector<vector<int>>& grid) {
        int sea = 0;
        vector<vector<int>> dp(grid);
        queue<pair<int, int>> list;
        int len = grid.size();
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                if(grid[i][j]==1){
                    pair<int, int> temp(i, j);
                    list.push(temp);
                }else
                    sea++;
            }
        }
        if(sea==0||list.size()==0)
            return -1;
        int cnt = 0;
        while(!list.empty()){
            int size = list.size();
            pair<int, int> temp;
            while(size--){
                temp = list.front();
                list.pop();
                for (int i = 0; i < 4;i++){
                    if(temp.first+x[i]>=0&&temp.first+x[i]<len){
                        if (temp.second + y[i] >= 0&&temp.second+y[i]<len){
                            pair<int, int> loca(temp.first + x[i], temp.second + y[i]);
                            if(dp[loca.first][loca.second]==0){
                                dp[loca.first][loca.second] = 1;
                                list.push(loca);
                            }
                            
                        }
                    }
                }
            }
            cnt++;
        }
        return cnt-1;
    }
};
// @lc code=end

