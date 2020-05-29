/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long int, TreeNode *>> list;
        pair<long long int, TreeNode *> temp, left, right;
        int size = 0, cnt = 0;
        long long int bias = 0, Min = 0, ans = 0;
        temp.first = 1, temp.second = root;
        if(root != nullptr)
            list.push(temp);
        while(!list.empty()){
            size = list.size();
            bias = pow(2, cnt) - 1;
            int flag = 1;
            while(size--){
                temp = list.front();
                list.pop();
                if(flag){
                    Min = temp.first - bias;
                    flag = 0;
                }
                long long int t = temp.first - bias - Min + 1;
                ans = max(t, ans);
                if(temp.second->left != nullptr){
                    left.first = temp.first * 2;
                    left.second = temp.second->left;
                    list.push(left);
                }
                if(temp.second->right != nullptr){
                    right.first = temp.first * 2 + 1;
                    right.second = temp.second->right;
                    list.push(right);
                }
            }
            cnt++;
        }
        return ans;
    }
};
// @lc code=end

