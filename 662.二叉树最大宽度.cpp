/*
@lc app=leetcode.cn id=662 lang=cpp
 *
[662] 二叉树最大宽度
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
// #include <map>
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<int, TreeNode *>> list;
        int size = 0;
        pair<long long unsigned, TreeNode *> temp(1, root), cache;
        pair<long long unsigned, TreeNode *> s, e;
        long long unsigned cnt = 0;
        if(temp.second != nullptr)
            list.push(temp);
        while(!list.empty()){
            size = list.size();
            s = list.front();
            while(size--){
                if(size == 0)
                    e = list.front();
                temp = list.front();
                list.pop();
                if(temp.second->left != nullptr){
                    cache.first = temp.first * 2;
                    cache.second = temp.second->left;
                    list.push(cache);
                }
                if(temp.second->right != nullptr){
                    cache.first = temp.first * 2 + 1;
                    cache.second = temp.second->right;
                    list.push(cache);
                }
            }
            cnt = max(e.first - s.first + 1, cnt);
        }
        return (int)cnt;
    }
};
// @lc code=end

