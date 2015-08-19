/*
 * main.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */


#include <iostream>
#include "binaryminheap.hpp"

int main(){
	BinaryMinHeap heap(20);
	/*
	heap.insert(100);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(3);
	heap.insert(6);
	heap.insert(4);
	heap.insert(8);
	heap.insert(10);
	heap.insert(23);
	 */
	int a[11] = {100, 2, 3, 4, 5, 3, 6, 4, 8, 10, 23};
	heap.convert(a, 11);
	std::cout << "Min:" << heap.findMin() << std::endl;
	heap.print();
	return 0;
}
