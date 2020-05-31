/*
@lc app=leetcode.cn id=449 lang=cpp
 *
[449] 序列化和反序列化二叉搜索树
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
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string d1, d2;
        Order(root, d1, d2);
        return d1 + "+" + d2;
    }
    void Order(TreeNode* root, string &data1, string &data2){
        if(root == nullptr)
            return;
        data1 += to_string(root->val) + ',';
        Order(root->left, data1, data2);
        data2 += to_string(root->val) + ',';
        Order(root->right, data1, data2);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string preOrder, inOrder, temp;
        int flag = 0;
        for(auto c:data){
            if(c == '+'){
                flag = ~flag;
                continue;
            }
            if(flag)
                inOrder.push_back(c);
            else
                preOrder.push_back(c);
        }
        vector<int> in, pre;
        for(auto c:inOrder){
            if(c == ','){
                in.push_back(stoi(temp));
                temp.clear();
            }else
                temp.push_back(c);
        }
        for(auto c:preOrder){
            if(c == ','){
                pre.push_back(stoi(temp));
                temp.clear();
            }else
                temp.push_back(c);
        }
        return buildTree(pre, in, 0, 0, in.size() - 1);
    }
    TreeNode* buildTree(vector<int> pre, vector<int> in, int index, int s, int e){
        if(s > e)
            return nullptr;
        TreeNode *root = new TreeNode(pre[index]);
        int temp = s;
        while(pre[index] != in[temp])
            temp++;
        root->left = buildTree(pre, in, index + 1, s, temp - 1);
        root->right = buildTree(pre, in, index + temp - s + 1, temp + 1, e);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

