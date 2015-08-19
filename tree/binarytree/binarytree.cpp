/*
 * binarytree.cpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */
#include <iostream>
#include <stack>
#include <utility>
#include "binarytree.hpp"

BinaryTree::BinaryTree(int val):root(new TreeNode(val)){}

BinaryTree::BinaryTree(const BinaryTree &tree):root(new TreeNode(tree.root->_val)){

}

BinaryTree & BinaryTree::operator =(const BinaryTree &tree){
	return *this;
}

BinaryTree::~BinaryTree(){
	dispose(root);
}

void BinaryTree::dispose(TreeNode *root){
	if(root == nullptr){
		return;
	}
	dispose(root->left);
	dispose(root->right);
	delete root;
}

int BinaryTree::findMin(){
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

int BinaryTree::findMin(TreeNode *root){
	if(root == nullptr){
		return -1;
	}else if(root->left == nullptr){
		return root->_val;
	}else{
		return findMin(root->left);
	}
}

int BinaryTree::findMax(){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return -1;
	}
	TreeNode *p = root;
	while(p->right != nullptr){
		p = p->right;
	}
	return p->_val;
}

int BinaryTree::findMax(TreeNode *root){
	if(root == nullptr){
		return -1;
	}else if(root->right == nullptr){
		return root->_val;
	}else {
		return findMax(root->right);
	}
}

TreeNode* BinaryTree::find(int x){
	TreeNode *p = root;
	while(p != nullptr){
		if(x < p->_val){
			p = p->left;
		}else if(x > p->_val){
			p = p->right;
		}else {
			break;
		}
	}
	return p;
}

void BinaryTree::insert(int x){
	root = insert(root, x);
}

TreeNode* BinaryTree::insert(TreeNode *root, int x){
	if(root == nullptr){
		root = new TreeNode(x);
	}else if(x < root->_val) {
		root->left = insert(root->left, x);
	}else if(x > root->_val){
		root->right = insert(root->right, x);
	}
	return root;
}

void BinaryTree::remove(int x){
	root = remove(root, x);
}

TreeNode* BinaryTree::remove(TreeNode *root, int x){
	if(root == nullptr){
		return nullptr;
	}else if(x < root->_val){
		root->left = remove(root->left, x);
	}else if(x > root->_val){
		root->right = remove(root->right, x);
	}else {
		if(root->left == nullptr && root->right == nullptr){
			delete root;
			return nullptr;
		}else if(root->left != nullptr && root->right != nullptr){
			int min = findMin(root->right);
			root->_val = min;
			root->right = remove(root->right, min);
		}else if(root->left != nullptr){
			/*
			root->_val = root->left->_val;
			root->left = remove(root->left, root->_val);
			*/
			//减少递归深度
			TreeNode *tmp = root;
			root = root->left;
			delete tmp;
		}else if(root->right != nullptr){
			/*
			root->_val = root->right->_val;
			root->right = remove(root->right, root->_val);
			*/
			TreeNode *tmp = root;
			root = root->right;
			delete tmp;
		}
	}
	return root;
}

void BinaryTree::preOrderRecursion(TreeNode *root){
	if(root == nullptr){
		return;
	}
	std::cout << root->_val << '\t' ;
	preOrderRecursion(root->left);
	preOrderRecursion(root->right);
}

void BinaryTree::inOrderRecursion(TreeNode *root){
	if (root == nullptr) {
		return;
	}
	inOrderRecursion(root->left);
	std::cout << root->_val << '\t';
	inOrderRecursion(root->right);
}

void BinaryTree::suOrderRecursion(TreeNode *root){
	if (root == nullptr) {
		std::cout << std::endl;
		return;
	}
	suOrderRecursion(root->left);
	suOrderRecursion(root->right);
	std::cout << root->_val << '\t';
}

void BinaryTree::inOrder(){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return;
	}
	std::stack<TreeNode*> s;
	TreeNode *p = root;
	while(!s.empty() || p != nullptr){
		while(p != nullptr ){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			std::cout << p->_val << '\t';
			p = p->right;
		}
	}
	std::cout << std::endl;
}

void BinaryTree::preOrder(){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return;
	}
	TreeNode *p = root;
	std::stack<TreeNode*> s;
	while(p != nullptr || !s.empty()){
		while(p != nullptr){
			std::cout << p->_val << '\t';
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	std::cout << std::endl;
}

void BinaryTree::suOrder(){
	if(root == nullptr){
		std::cerr << "tree is empty" << std::endl;
		return;
	}
	std::stack<TreeNode*> s;
	TreeNode *p = root;
	TreeNode *lastVisit = nullptr;
	while(p != nullptr || !s.empty()){
		while(p != nullptr){
			s.push(p);
			p = p->left;
		}
		p = s.top();
		if(p->right == nullptr || p->right == lastVisit){
			std::cout << p->_val << '\t';
			lastVisit = p;
			p = nullptr;
			s.pop();
		}else {
			p = p->right;
		}
		/*
		if(p != nullptr){
			s.push(p);
			p = p->left;
		}else {
			p = s.top();
			s.pop();
			p = p->right;
		}
		*/
	}
}

void BinaryTree::postOrder(){
	using std::make_pair;
	std::stack<std::pair<TreeNode*, bool>> s;
	s.push(make_pair(root, false));
	while(!s.empty()){
		std::pair<TreeNode*, bool> t = s.top();
		s.pop();
		if(t.first == nullptr){
			continue;
		}
		if(t.second){
			std::cout << t.first->_val << '\t';
		}else {
			s.push(make_pair(t.first, true));
			s.push(make_pair(t.first->right, false));
			s.push(make_pair(t.first->left, false));
		}
	}
	std::cout << std::endl;
}




