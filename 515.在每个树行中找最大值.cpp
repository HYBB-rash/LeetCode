/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start

// * Definition for a binary tree node.


// #include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> list;
        int size = 0, imax = INT32_MIN;
        TreeNode *temp;
        if(root != nullptr)
            list.push(root);
        while(!list.empty()){
            size = list.size();
            while(size--){
                temp = list.front();
                list.pop();
                if(temp->left != nullptr)
                    list.push(temp->left);
                if(temp->right != nullptr)
                    list.push(temp->right);
                imax = max(imax, temp->val);
            }
            ans.push_back(imax);
            imax = INT32_MIN;
        }
        return ans;
    }
};
// @lc code=end

