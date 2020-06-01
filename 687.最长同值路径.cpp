/*
@lc app=leetcode.cn id=687 lang=cpp
 *
[687] 最长同值路径
 */

// @lc code=start
/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
// #include <algorithm>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    int max_edge = 0;
    int dfs(TreeNode *root){
        if(root == nullptr)
            return 0;
        int left = dfs(root->left);
        if(root->left != nullptr && root->val == root->left->val)
            left++;
        else
            left = 0;
        int right = dfs(root->right);
        if(root->right != nullptr && root->val == root->right->val)
            right++;
        else
            right = 0;
        max_edge = max(max_edge, left + right);
        return left > right ? left : right;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max_edge;
    }
};
// @lc code=end

