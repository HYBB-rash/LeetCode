/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.71%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 95.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include<iostream>
// #include<algorithm>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    int max_ans = 0x80000000;
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root->left) + root->val;
        int right = dfs(root->right) + root->val;
        int total = right + left - root->val;
        int res = max(total, max(root->val, max(left, right)));
        max_ans = max(max_ans, res);
        return max(max(left, right), root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_ans;
    }
};
// @lc code=end

