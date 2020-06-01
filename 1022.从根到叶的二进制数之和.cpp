/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sum = 0, cnt = 0;
    int sumRootToLeaf(TreeNode* root) {
        sss(root, 0);
        return sum;
    }
    int sss(TreeNode *root, int cnt){
        if(root == nullptr)
            return sum;
        cnt += root->val;
        if(root->left == nullptr && root->right == nullptr)
            sum += cnt;
        sss(root->left, cnt << 1);
        sss(root->right, cnt << 1);
        return sum;
    }
};
// @lc code=end

