/*
 * main.cpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */
#include <iostream>
#include "avltree.hpp"

int main(){
	AvlTree t;
	t.insert(1);
	t.insert(2);
	t.insert(3);
	t.insert(4);
	t.insert(5);
	preOrder(t.getRoot());
	std::cout << std::endl;
	t.preOrder();
	inOrder(t.getRoot());
	std::cout << std::endl;
	t.inOrder();
	postOrder(t.getRoot());
	std::cout << std::endl;
	t.postOrder();
	std::cout << "Height:" << t.getHeight() << std::endl;
	AvlTree t1(t);
	std::cout << "t1 Height:" << t1.getHeight() << std::endl;
	AvlTree t2;
	t2 = t;
	std::cout << "t2 Height:" << t2.getHeight() << std::endl;
	t.insert(9);
	t.inOrder();
	t1.inOrder();
	t2.inOrder();
	return 0;
}

