/*
@lc app=leetcode.cn id=508 lang=cpp
 *
[508] 出现次数最多的子树元素和
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
// #include <algorithm>
// #include <map>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    map<int, int> dict;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum = 0, temp = INT32_MIN;
        getSum(root, sum);
        vector<int> ans;
        for(auto key:dict){
            if(temp < key.second){
                ans.clear();
                temp = key.second;
            }
            if(key.second == temp)
                ans.push_back(key.first);
        }
        return ans;
    }
    void getSum(TreeNode *root, int &sum){
        if(root == nullptr)
            return;
        int left = 0, right = 0;
        getSum(root->left, left);
        getSum(root->right, right);
        sum = left + right + root->val;
        dict[sum]++;
    }
};
// @lc code=end

