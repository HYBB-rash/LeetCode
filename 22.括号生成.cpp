/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.57%)
 * Likes:    850
 * Dislikes: 0
 * Total Accepted:    96K
 * Total Submissions: 129.8K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string temp;
        dfs(n, n, temp);
        return ans;
    }
    void dfs(int left,int right,string curstr){
        if(left==0&&right==0){
            ans.push_back(curstr);
            return;
        }
        if(left>0)
            dfs(left - 1, right, curstr+"(");
        if(right>left)
            dfs(left, right - 1, curstr + ")");
    }
};
// @lc code=end

