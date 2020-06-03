/*
@lc app=leetcode.cn id=894 lang=cpp
 *
[894] 所有可能的满二叉树
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
#include <vector>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode *> list;
    vector<pair<int, int>> choice;
    void dfs(TreeNode *root, int times){
        if(times < 0)
            return;
        
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        choice.push_back(pair<int, int>(1, 1));
        choice.push_back(pair<int, int>(1, 0));
        choice.push_back(pair<int, int>(0, 1));
    }
};
// @lc code=end

