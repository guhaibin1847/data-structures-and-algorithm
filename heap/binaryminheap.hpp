/*
 * binaryminheap.hpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#ifndef BINARYMINHEAP_HPP_
#define BINARYMINHEAP_HPP_

#define DEFAULT_HEAP_CAPACITY 10

class BinaryMinHeap {
public :
	BinaryMinHeap():_capacity(DEFAULT_HEAP_CAPACITY+1),_size(0),data(new int[DEFAULT_HEAP_CAPACITY+1]){}
	BinaryMinHeap(int capacity):_capacity(capacity+1), _size(0), data(new int[capacity+1]){}
	BinaryMinHeap(const BinaryMinHeap &heap);
	BinaryMinHeap& operator=(const BinaryMinHeap &heap);
	~BinaryMinHeap();

	void percolateUp(int i);
	void percolateDown(int i);
	void insert(int x);
	int findMin();
	int removeMin();
	void convert(int arr[], int length);//将一个数组转成最小堆
	bool isEmpty(){
		return _size == 0;
	}
	bool isFull(){
		return _size == _capacity;
	}
	void print();
private :
	int _capacity;
	int _size;
	int *data;
};


#endif /* BINARYMINHEAP_HPP_ */
