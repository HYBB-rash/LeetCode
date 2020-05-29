/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val == key){
            if(root->right){
                TreeNode *right = root->right;
                while(right->left)
                    right = right->left;
                right->left = root->left;
                root->left = nullptr;
                root = root->right;
            }else if (!root->right && !root->left)
                return nullptr;
            else
                root = root->left;
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end

