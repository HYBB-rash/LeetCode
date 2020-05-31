/*
@lc app=leetcode.cn id=652 lang=cpp
 *
[652] 寻找重复的子树
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
// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>
// #include <queue>
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
    vector<TreeNode *> list;
    map<string, pair<TreeNode *, int>> dict;
    void DFS_getNodeList(TreeNode *root){
        if(root == nullptr)
            return;
        string str;
        se(root, str);
        if(dict.find(str) == dict.end())
            dict[str] = pair<TreeNode *, int>(root, 1);
        else
            dict[str].second += 1;
        DFS_getNodeList(root->left);
        DFS_getNodeList(root->right);
    }
    void se(TreeNode *root, string &str){
        queue<TreeNode *> list;
        int size = 0;
        TreeNode *temp;
        if(root != nullptr)
            list.push(root);
        while(!list.empty()){
            size = list.size();
            while(size--){
                temp = list.front();
                list.pop();
                if(temp == nullptr)
                    str += "null,";
                else{
                    str += to_string(temp->val) + ',';
                    list.push(temp->left);
                    list.push(temp->right);
                }
            }
        }
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        DFS_getNodeList(root);
        for(auto key:dict)
            if(key.second.second >= 2)
                list.push_back(key.second.first);
        return list;
    }
};
// @lc code=end

