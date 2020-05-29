/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start

// * Definition for a binary tree node.
// #include <iostream>
// #include <string>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == nullptr)
            return "";
        string str = to_string(t->val);
        if(t->left != nullptr || (t->right != nullptr))
            str += "(" + tree2str(t->left) + ")";
        if(t->right != nullptr)
            str += "(" + tree2str(t->right) + ")";
        return str;
    }
};
// @lc code=end

