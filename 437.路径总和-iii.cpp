/*
@lc app=leetcode.cn id=437 lang=cpp
 *
[437] 路径总和 III
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
// #include <iostream>
// #include <vector>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    int ans_cnt = 0, path_cnt = 0;
    vector<int> temp_path;
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return path_cnt;
    }
    void pathNum(TreeNode* root, int sum){
        if(root == nullptr)
            return ;
        if(sum - root->val == 0)
            path_cnt++;
        pathNum(root->left, sum - root->val);
        pathNum(root->right, sum - root->val);
    }
    void dfs(TreeNode* root, int sum){
        if(root == nullptr)
            return;
        pathNum(root, sum);
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};
// @lc code=end

