/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;
    vector<int> inT, preT;
    vector<int> tempIn, tempPre;
    void dfs(TreeNode *s, vector<int> &preOrder, vector<int> &inOrder){
        if(s == nullptr)
            return;
        preOrder.push_back(s->val);
        dfs(s->left, preOrder, inOrder);
        inOrder.push_back(s->val);
        dfs(s->right, preOrder, inOrder);
    }
    void helper(TreeNode *s, TreeNode *t){
        if(s == nullptr || ans)
            return;
        if(s->val == t->val){
            tempIn.clear(), tempPre.clear();
            dfs(s, tempPre, tempIn);
            ans = ans || (tempPre == preT && tempIn ==  inT);
        }
        helper(s->left, t);
        helper(s->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        dfs(t, preT, inT);
        helper(s, t);
        return ans;
    }

};
// @lc code=end

