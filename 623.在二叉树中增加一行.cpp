/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode *> list;
        if(root != nullptr)
            list.push(root);
        if(d == 1){
            TreeNode *t = new TreeNode(v);
            t->left = root;
            return t;
        }
        int size = 0, dep = 1;
        TreeNode *temp = nullptr;
        while(!list.empty()){
            size = list.size();
            while(size--){
                temp = list.front();
                list.pop();
                if(dep + 1 == d){
                    TreeNode *left = nullptr, *right = nullptr;
                    left = new TreeNode(v);
                    right = new TreeNode(v);
                    left->left = temp->left;
                    temp->left = left;
                    right->right = temp->right;
                    temp->right = right;
                }
                if(temp->left != nullptr)
                    list.push(temp->left);
                if(temp->right != nullptr)
                    list.push(temp->right);
            }
            dep++;
        }
        return root;
    }
};
// @lc code=end

