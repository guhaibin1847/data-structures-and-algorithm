/*
 * binaryminheap.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#include <iostream>
#include "binaryminheap.hpp"

BinaryMinHeap::BinaryMinHeap(const BinaryMinHeap &heap):
	_capacity(heap._capacity), _size(heap._size), data(new int[heap._capacity]){
	for(int i = 0 ; i < _size ; ++i){
		this->data[i] = heap.data[i];
	}
}

BinaryMinHeap& BinaryMinHeap::operator=(const BinaryMinHeap &heap){
	if(this == &heap){
		return *this;
	}
	//新建一个临时变量，和当前对象进行交换
	BinaryMinHeap h(heap);
	this->_capacity = heap._capacity;
	this->_size = heap._size;
	int *tmp = h.data;
	h.data = this->data;
	this->data = tmp;
	return *this;
}

BinaryMinHeap::~BinaryMinHeap(){
	if(data != nullptr)
		delete[] data;
}

void BinaryMinHeap::percolateUp(int i){
	int element = data[i];
	for( ; data[i / 2] > element && i > 1; i /= 2){
		data[i] = data[i / 2];
	}
	data[i] = element;
}

void BinaryMinHeap::percolateDown(int i){
	int element = data[i];
	int child;
	while(i * 2 < _size && i > 0){
		child = i * 2;
		if(child < _size && data[child+1] < data[child]){
			++child;
		}
		if(data[child] < element){
			data[i] = data[child];
			i = child;
		}else {
			break;
		}
	}
	data[i] = element;
}

void BinaryMinHeap::insert(int x){
	if(isFull()){
		std::cerr << "heap is full" << std::endl;
		return;
	}
	/*
	data[++_size] = x;
	percolateUp(_size);
	*/
	++_size;
	int i = _size ;
	for(; data[i / 2] > x && i > 1 ; i /= 2){
		data[i] = data[i/2];
	}
	data[i] = x;
}

int BinaryMinHeap::findMin(){
	if(isEmpty()){
		std::cerr << "heap is empty" << std::endl;
		return -1;
	}
	return data[1];
}

int BinaryMinHeap::removeMin(){
	int min = data[1];
	data[1] = data[_size--];
	percolateDown(1);
	//以下代码等价
	/*
	int x = data[_size--];
	int i = 1;
	int child;
	for(; i < _size ; i = child){
		child = i * i;
		if(child  < _size && data[child+1] < data[child]){
			++child;
		}
		if(data[child] < x){
			data[i] = data[child];
		}else {
			break;
		}
	}
	data[i] = x;
	*/
	return min;
}

void BinaryMinHeap::convert(int *arr, int length){
	BinaryMinHeap h(length+1);
	for(int i = 0 ; i < length ; ++i){
		h.data[i+1] = arr[i];
		h._size++;
	}
	for(int i = (length) / 2 ; i > 0 ; --i){
		h.percolateDown(i);
	}
	this->_capacity = h._capacity;
	this->_size = h._size;
	int *tmp = this->data;
	this->data = h.data;
	h.data = tmp;
}

void BinaryMinHeap::print(){
	for(int i = 0 ; i <= _size ; ++i){
		std::cout << data[i] << '\t' ;
	}
	std::cout << std::endl;
}







