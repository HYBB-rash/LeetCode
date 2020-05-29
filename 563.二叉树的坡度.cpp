/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode *root, int &sum){
        if(!root)
            return 0;
        int left = 0, right = 0;
        dfs(root->left, left);
        dfs(root->right, right);
        ans += abs(left - right);
        sum = left + right + root->val;
        return 0;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return ans;
    }
};
// @lc code=end

