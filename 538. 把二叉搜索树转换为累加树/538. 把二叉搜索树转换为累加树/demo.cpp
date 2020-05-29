
#include<iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int count = 0;
TreeNode* convertBST(TreeNode* root) {
	if (root == NULL) return root;
	root->right = convertBST(root->right);
	root->val += count;
	count = root->val;
	root->left = convertBST(root->left);
}
