/*
@lc app=leetcode.cn id=872 lang=cpp
 *
[872] 叶子相似的树
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
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr)
            return;
        dfs(root->left, ans);
        if(root->left == nullptr && root->right == nullptr)
            ans.push_back(root->val);
        dfs(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        return list1 == list2;
    }
};
// @lc code=end

