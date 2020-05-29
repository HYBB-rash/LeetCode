/*
@lc app=leetcode.cn id=671 lang=cpp
 *
[671] 二叉树中第二小的节点
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
#include <iostream>
#include <set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int ans = INT32_MAX;
    set<int> temp;
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return ans;
        temp.insert(root->val);
        temp.insert(root->left->val);
        temp.insert(root->right->val);
        int target = 0;
        if(temp.size() == 1)
            target = -1;
        int cnt = 0;
        for(int a:temp)
            if(cnt == 1)
                target = a;
    }
};
// @lc code=end

