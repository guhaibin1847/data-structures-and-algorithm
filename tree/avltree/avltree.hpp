/*
 * avltree.hpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

struct TreeNode {
	int _val;
	int height;
	bool isRemove;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val):_val(val),height(0), left(nullptr), right(nullptr), isRemove(false){}
};

class AvlTree {
public :
	AvlTree():root(nullptr){}
	AvlTree(int val):root(new TreeNode(val)){}
	AvlTree(const AvlTree &tree);
	AvlTree& operator=(const AvlTree &tree);
	~AvlTree();
	int findMin();
	int findMax();
	TreeNode* find(int x);
	void insert(int x);
	//void remove(int x);
	void preOrder();
	void inOrder();
	void postOrder();
	int getHeight(){
		return root->height;
	}
	TreeNode* getRoot(){
		return root;
	}
private :
	TreeNode *root;
};

void dispose(TreeNode *root);
int findMin(TreeNode *root);
int findMax(TreeNode *root);
inline int height(TreeNode *root);
inline int max(int x, int y);
//假设在a处发生了不平衡
//在a的左孩子的左子树进行插入，进行单右旋转
TreeNode* singleRoteWithLeft(TreeNode *t);
//在a的左孩子的右子树进行插入，先左旋，后右旋
TreeNode* doubleRoteWithLeft(TreeNode *t);
//在a的右孩子的右子树进行插入，进行单左旋转
TreeNode* singleRoteWithRight(TreeNode *t);
//在a的右孩子的左子树进行插入，先右旋，后左旋
TreeNode* doubleRoteWithRight(TreeNode *t);
TreeNode* insert(TreeNode *root, int x);

void visit(TreeNode *p);

void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);

#endif /* AVLTREE_HPP_ */
