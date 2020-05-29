#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	vector<int> ans;
	bool flag = false;
	void DFS(TreeNode* root)
	{
		if (root == nullptr||flag) return;
		DFS(root->left);
		ans.push_back(root->val);
		if (ans.size() == 2)
			if (ans[1] > ans[0]) ans[0] = ans[1], ans.pop_back();
			else flag = true;
		DFS(root->right);
	}
	bool isValidBST(TreeNode* root) {
		DFS(root);
		return !flag;
	}
};