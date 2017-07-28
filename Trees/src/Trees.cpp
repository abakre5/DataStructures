//============================================================================
// Name        : Trees.cpp
// Author      : AbhishekBakare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "trees.h"

int main() {
	Trees t;
	t.createTree();
	t.inOrder(t.getRoot());
	breakLine
	t.preOrder(t.getRoot());
	breakLine
	t.postOrder(t.getRoot());
	breakLine
	cout << "\nHeight Of Tree :: " << t.heightOfTree(t.getRoot()) << endl;
	cout << "Size Of Tree :: " << t.sizeOfTree(t.getRoot()) << endl;
	t.isBst(t.getRoot(), INT_MIN, INT_MAX) ? cout << "Tree is BST" << endl : cout << "Tree is not BST" << endl;
	t.deleteFromTree(t.getRoot(), generateRandom())	? cout << "Found and Deleted" << endl : cout << "Not Found" << endl;
	cout << "LCA :: " << t.lca(t.getRoot(), generateRandom(), generateRandom())->getData() << endl;
	node *pre = NULL, *suc = NULL;
	t.findPreSuc(t.getRoot(), pre, suc, generateRandom());
	pre ? cout << "Predecessor :: " << pre->getData() : cout << "No Predecessor";
  breakLine
  suc ? cout << "Successor :: " << suc->getData() : cout << "No Successor";
	breakLine
	return 0;
}
