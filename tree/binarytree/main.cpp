/*
 * main.cpp
 *
 *  Created on: 2015年8月18日
 *      Author: bean
 */

#include "binarytree.hpp"
#include <iostream>

int main(){
	BinaryTree t;
	t.insert(5);
	t.insert(28);
	t.insert(10);
	t.insert(18);
	t.insert(2);
	t.insert(1);
	t.insert(4);
	std::cout << "min: " << t.findMin() << std::endl;
	std::cout << "max: " << t.findMax() << std::endl;
	t.inOrderRecursion(t.getRoot());
	std::cout << std::endl;
	t.remove(5);
	t.inOrder();
	t.preOrder();
	t.postOrder();
	t.suOrder();
	std::cout << std::endl;
	return 0;
}


