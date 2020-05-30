/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    TreeNode *temp;
    bool ans = false;
    bool find(TreeNode *root, int k){
        if(root == nullptr || ans)
            return ans;
        find(root->left, k);
        int target = k - root->val;
        TreeNode *s = temp;
        while(s){
            if(target > s->val)
                s = s->right;
            else if(target < s->val)
                s = s->left;
            else{
                ans = ans || !(s == root);
                return ans;
            }
        }
        find(root->right, k);
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        temp = root;
        return find(root, k);
    }
};
// @lc code=end

