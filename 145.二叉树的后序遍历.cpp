/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> order;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return order;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        order.push_back(root->val);
        return order;
    }
};
// @lc code=end

