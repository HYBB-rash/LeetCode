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
// #include <iostream>
// #include <set>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    long int ans = INT64_MAX;
    set<int> temp;
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr)
            return -1;
        if(!(root->left == nullptr && root->right == nullptr)){
            temp.insert(root->left->val);
            temp.insert(root->right->val);
            temp.insert(root->val);
            long int cnt = 0, memo = 0;
            if(temp.size() != 1)
                for(int v:temp){
                    if(cnt == 1)
                        memo = v;
                    cnt++;
                }
            if(cnt == 2)
                ans = min(ans, memo);
            temp.clear();
        }
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);
        return ans != INT64_MAX ? ans : -1;
    }
};
// @lc code=end

