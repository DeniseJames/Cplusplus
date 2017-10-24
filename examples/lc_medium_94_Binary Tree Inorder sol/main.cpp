#include <iostream>
#include "BinaryTree.h"
#include <cstdlib>

using namespace std;
//* Definition for a binary tree node.
int main() {
	int Treevalues[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BinaryTree mytree;
	cout << " Printing the tree in order before adding numbers " << endl;
	mytree.PrintInOrder();
	cout << " Printing the tree in order after adding numbers " << endl;
	for (size_t i = 0; i < 16; i++)
	{
		mytree.AddLeaf(Treevalues[i]);
	}
	mytree.PrintInOrder();
	return 0;
}


