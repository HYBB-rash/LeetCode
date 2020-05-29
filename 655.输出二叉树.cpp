/*
@lc app=leetcode.cn id=655 lang=cpp
 *
[655] 输出二叉树
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
// #include <string>
// #include <cmath>
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
    int deep = 0;
    vector<vector<string>> ans;
    void getDepth(TreeNode *root, int dep){
        if(root == nullptr)
            return;
        deep = max(deep, dep);
        getDepth(root->left, dep + 1);
        getDepth(root->right, dep + 1);
    }
    void p(TreeNode* root,int dep, int s, int e){
        if(root == nullptr)
            return;
        int temp = (e + s) / 2;
        ans[dep][temp] = to_string(root->val);
        p(root->left, dep + 1, s, temp - 1);
        p(root->right, dep + 1, temp + 1, e);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        getDepth(root, 1);
        int size = pow(2, deep) - 1;
        ans.resize(deep);
        for (int i = 0; i < deep; i++)
            ans[i].resize(size);
        p(root, 0, 0, size - 1);
        return ans;
    }
};
// @lc code=end

