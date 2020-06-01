/*
@lc app=leetcode.cn id=993 lang=cpp
 *
[993] 二叉树的堂兄弟节点
 */

// @lc code=start
/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
// #include <map>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    
    pair<TreeNode *, int> getFather(TreeNode *root, int val, int height){
        if(root == nullptr)
            return pair<TreeNode *, int>(nullptr, 0);
        pair<TreeNode *, int> father;
        if(root->val == val){
            father.first = root;
            father.second = height - 1;
        }
        if(root->left != nullptr && root->left->val == val){
            father.first = root;
            father.second = height;
        }
        if(root->right != nullptr && root->right->val == val){
            father.first = root;
            father.second = height;
        }
        father = father.first != nullptr ? father : getFather(root->left, val, height + 1);
        father = father.first != nullptr ? father : getFather(root->right, val, height + 1);
        return father;
        }
    bool isCousins(TreeNode* root, int x, int y) {
        auto fa1 = getFather(root, x, 0);
        auto fa2 = getFather(root, y, 0);
        return fa1.second == fa2.second && fa1.first != fa2.first;
    }
};
// @lc code=end

