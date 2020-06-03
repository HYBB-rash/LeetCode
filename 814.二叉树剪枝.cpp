/*
@lc app=leetcode.cn id=814 lang=cpp
 *
[814] 二叉树剪枝
 */

// @lc code=start
/**
Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    TreeNode* dfs(TreeNode* root, bool &flag){
        if(root == nullptr)
            return nullptr;
        bool flag_left = false, flag_right = false;
        root->left = dfs(root->left, flag_left);
        root->right = dfs(root->right, flag_right);
        flag = flag_left || flag_right || root->val;
        return flag ? root : nullptr;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = false;
        return dfs(root, flag);
    }
};
// @lc code=end

