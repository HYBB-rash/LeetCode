/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    map<int, int> dict, ans;
    vector<int> cnt;
    void dfs(TreeNode* root){
        if(root == nullptr)
            return;
        dict[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    int ddd(TreeNode *root){
        if(root != nullptr)
            return 0;
        int left = ddd(root->left);
        int right = ddd(root->right);
        if(ans[root->val])
            cnt.push_back(left + right + root->val);
        return ans[root->val] ? left + right + root->val : left + right;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int max_cnt = -1;
        for(pair<int, int> p:dict){
            if(p.second > max_cnt){
                max_cnt = p.second;
                ans.clear();
            }
            cout << p.first << endl;
            ans[p.first] = 1;
        }
        ddd(root);
        return cnt;
    }
};
// @lc code=end

