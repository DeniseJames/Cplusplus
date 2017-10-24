#pragma once

class BinaryTree {
private:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode* root_;
	void PrivateAddLeaf(int val, TreeNode* ptr);
	void PrintInOrderPrivate(TreeNode* ptr);

public:
	BinaryTree();
	TreeNode* CreateLeaf(int val);
	void AddLeaf(int val);
	void PrintInOrder();
};
