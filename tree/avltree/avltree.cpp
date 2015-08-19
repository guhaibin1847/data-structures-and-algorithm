/*
 * avltree.cpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */

#include <iostream>
#include <stack>
#include <utility>
#include "avltree.hpp"

int findMin(TreeNode *root){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return -1;
	}
	if(root->left == nullptr){
		return root->_val;
	}else {
		return findMin(root->left);
	}
}

int findMax(TreeNode *root){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return -1;
	}
	if(root->right == nullptr){
		return root->_val;
	}else {
		return findMax(root->right);
	}
}

void dispose(TreeNode *root){
	if(root != nullptr){
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}

int max(int x, int y){
	return x > y ? x : y;
}
/*
int height(TreeNode *root){
	if(root == nullptr){
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int h = left > right ? left : right;
	return h+1;
}
*/
int height(TreeNode *node){
	if(node == nullptr){
		return -1;
	}
	return node->height;
}
//返回调整后的根节点
TreeNode* singleRoteWithLeft(TreeNode *t){
	TreeNode *k2 = t->left;
	t->left = k2->right;
	k2->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	return k2;
}

TreeNode* doubleRoteWithLeft(TreeNode *t){
	t->left = singleRoteWithRight(t->left);
	return singleRoteWithLeft(t);
}

TreeNode* singleRoteWithRight(TreeNode *t){
	TreeNode *k2 = t->right;
	t->right = k2->left;
	k2->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	return k2;
}

TreeNode* doubleRoteWithRight(TreeNode *t){
	t->right = singleRoteWithLeft(t->right);
	return singleRoteWithRight(t);
}

TreeNode* insert(TreeNode *root, int x){
	if(root == nullptr){
		root = new TreeNode(x);
	}else if(x < root->_val){
		root->left = insert(root->left, x);
		if((height(root->left) - height(root->right)) == 2){
			if(x < root->left->_val){
				root = singleRoteWithLeft(root);
			}else {
				root = doubleRoteWithLeft(root);
			}
		}
	}else if(x > root->_val){
		root->right = insert(root->right, x);
		if((height(root->right) - height(root->left)) == 2){
			if(x < root->right->_val){
				root = doubleRoteWithRight(root);
			}else {
				root = singleRoteWithRight(root);
			}
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

void preOrder(TreeNode *root){
	if(root != nullptr){
		std::cout << root->_val << '\t';
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode *root){
	if(root != nullptr){
		inOrder(root->left);
		std::cout << root->_val << '\t';
		inOrder(root->right);
	}
}

void postOrder(TreeNode *root){
	if(root != nullptr){
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->_val << '\t';
	}
}

void visit(TreeNode *p){
	std::cout << p->_val << '\t';
}

TreeNode* deepCopy(TreeNode *from, TreeNode *to){
	if(from != nullptr){
		to = new TreeNode(from->_val);
		to->height = from->height;
		to->left = deepCopy(from->left, to->left);
		to->right = deepCopy(from->right, to->right);
	}
	return to;
}

/******************* member function *******************/
AvlTree::AvlTree(const AvlTree &tree):root(nullptr){
	root = deepCopy(tree.root, root);
}

AvlTree& AvlTree::operator =(const AvlTree &tree){
	if(this != &tree){
		AvlTree tmp(tree);
		TreeNode *tp = tmp.root;
		tmp.root = this->root;
		this->root = tp;
	}
	return *this;
}

AvlTree::~AvlTree(){
	dispose(root);
}

int AvlTree::findMin(){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return -1;
	}
	TreeNode *p = root;
	while(p->left != nullptr){
		p = p->left;
	}
	return p->_val;
}

int AvlTree::findMax(){
	if (root == nullptr) {
		std::cerr << "tree is empty" << std::endl;
		return -1;
	}
	TreeNode *p = root;
	while(p->right != nullptr){
		p = p->right;
	}
	return p->_val;
}

void AvlTree::insert(int x){
	root = ::insert(root, x);
}

void AvlTree::preOrder(){
	using std::make_pair;
	std::stack<std::pair<TreeNode*, bool>> s;
	s.push(make_pair(root, false));
	bool visited;
	while(!s.empty()){
		std::pair<TreeNode*, bool> t = s.top();
		TreeNode *p = t.first;
		visited = t.second;
		s.pop();
		if(p == nullptr){
			continue;
		}
		if(visited){
			visit(p);
		}else {
			s.push(make_pair(p->right, false));
			s.push(make_pair(p->left, false));
			s.push(make_pair(p, true));
		}
	}
	std::cout << std::endl;
}

void AvlTree::inOrder(){
	using std::make_pair;
	std::stack<std::pair<TreeNode*, bool>> s;
	s.push(make_pair(root, false));
	bool visited;
	while(!s.empty()){
		std::pair<TreeNode*, bool> t = s.top();
		s.pop();
		TreeNode *p = t.first;
		visited = t.second;
		if(p == nullptr){
			continue;
		}
		if(visited){
			visit(p);
		}else {
			s.push(make_pair(p->right, false));
			s.push(make_pair(p, true));
			s.push(make_pair(p->left, false));
		}
	}
	std::cout << std::endl;
}

void AvlTree::postOrder(){
	using std::make_pair;
	std::stack<std::pair<TreeNode*, bool>> s;
	s.push(make_pair(root, false));
	bool visited;
	while(!s.empty()){
		std::pair<TreeNode*, bool> t = s.top();
		s.pop();
		TreeNode *p = t.first;
		visited = t.second;
		if(p == nullptr){
			continue;
		}
		if(visited){
			visit(p);
		}else {
			s.push(make_pair(p, true));
			s.push(make_pair(p->right, false));
			s.push(make_pair(p->left, false));
		}
	}
	std::cout << std::endl;
}



