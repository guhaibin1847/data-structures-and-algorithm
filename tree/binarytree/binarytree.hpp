/*
 * binarytree.hpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */

#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

struct TreeNode {
	int _val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val):_val(val), left(nullptr), right(nullptr){}
};

class BinaryTree {
public :
	BinaryTree():root(nullptr){}
	BinaryTree(int val);
	BinaryTree(const BinaryTree &tree);
	BinaryTree& operator=(const BinaryTree &tree);
	~BinaryTree();
	int findMin();
	int findMax();
	TreeNode* find(int x);
	void insert(int x);
	void remove(int x);
	void preOrderRecursion(TreeNode *root);
	void inOrderRecursion(TreeNode *root);
	void suOrderRecursion(TreeNode *root);
	void preOrder();
	void inOrder();
	void suOrder();
	void postOrder();
	TreeNode* getRoot(){return root;}
private :
	void dispose(TreeNode *root);
	TreeNode* insert(TreeNode *root, int x);
	TreeNode* remove(TreeNode *root, int x);
	int findMin(TreeNode *root);
	int findMax(TreeNode *root);
	TreeNode *root;
};


#endif /* BINARYTREE_HPP_ */
