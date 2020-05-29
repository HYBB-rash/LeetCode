/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
// #include <stdio.h>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int size = 0, cnt = 0;
        if(root != nullptr) q.push(root);
        vector<vector<int>> ans;
        vector<int> temp;
        TreeNode *temp_n;
        while(!q.empty()){
            temp.clear();
            size = q.size();
            while(size--){
                temp_n = q.front();
                q.pop();
                if(temp_n->left != nullptr) q.push(temp_n->left);
                if(temp_n->right != nullptr) q.push(temp_n->right);
                temp.push_back(temp_n->val);
            }
            if(cnt % 2) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            cnt++;
        }
        return ans;
    }
};
// @lc code=end

