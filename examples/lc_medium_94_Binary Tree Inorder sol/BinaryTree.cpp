#include <iostream>
#include "BinaryTree.h"
#include <cstdlib>

BinaryTree::BinaryTree() {
	root_ = NULL;
}

BinaryTree::TreeNode* BinaryTree::CreateLeaf(int val) {

	TreeNode* n = new TreeNode;
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;

}
void BinaryTree::AddLeaf(int val) {
	PrivateAddLeaf(val, root_);

}

void BinaryTree::PrivateAddLeaf(int val, BinaryTree::TreeNode* ptr) {
	if (root_==NULL)
	{
		root_ = CreateLeaf(val);
	}
	else if (val < ptr->val)
	{
		if (ptr->left !=NULL)
		{
			PrivateAddLeaf(val, ptr->left); // recursively til NULL
		}
		else
		{
			ptr->left = CreateLeaf(val);
		}
	}
	else if (val > ptr->val)
	{
		if (ptr->right != NULL)
		{
			PrivateAddLeaf(val, ptr->right); // recursively til NULL
		}
		else
		{
			ptr->right = CreateLeaf(val);
		}
	}
	else
	{
		std::cout << " the value has already been added to the tree " << val << std::endl;

	}

}
void BinaryTree::PrintInOrder() {
	PrintInOrderPrivate(root_);
}
void BinaryTree::PrintInOrderPrivate(BinaryTree::TreeNode* ptr) {
	if (root_!=NULL)
	{
		if (ptr->left!=NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}
		std::cout << "  " << ptr->val;
		if (ptr->right!=NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		std::cout << " Tree is empty" << std::endl;
	}
}