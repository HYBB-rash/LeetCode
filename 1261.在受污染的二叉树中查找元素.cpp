/*
@lc app=leetcode.cn id=1261 lang=cpp
 *
[1261] 在受污染的二叉树中查找元素
 */

// @lc code=start
/**
Definition for a binary tree node.
 */
// #include <map>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class FindElements {
public:
    map<int, int> dict;
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    void dfs(TreeNode* root, int index){
        if(root == nullptr)
            return;
        dict[index] = true;
        dfs(root->left, index * 2 + 1);
        dfs(root->right, index * 2 + 2);
    }
    bool find(int target) {
        return dict[target];
    }
};

/**
Your FindElements object will be instantiated and called as such:
FindElements* obj = new FindElements(root);
bool param_1 = obj->find(target);
 */
// @lc code=end

