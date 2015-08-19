/*
 * queue.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#include <iostream>
#include "queue.hpp"

Queue::Queue(const Queue &queue):_size(queue._size), _capacity(queue._capacity), _head(queue._head), _tail(queue._tail), data(new int[_capacity]){
	if(_size != 0){
		int i ;
		for(i = queue._head ; i != queue._tail ;){
			data[i] = queue.data[i];
			++i;
			if(i == queue._capacity){
				i = 0;
			}
		}
		data[i] = queue.data[i];
	}
}

Queue& Queue::operator =(const Queue &queue){
	if(this != &queue){
		Queue tmp(queue);
		this->_capacity = tmp._capacity;
		this->_head = tmp._head;
		this->_size = tmp._size;
		this->_tail = tmp._tail;
		int *tp = tmp.data;
		tmp.data = this->data;
		this->data = tp;
	}
	return *this;
}


void Queue::offer(int x){
	if(isFull()){
		std::cerr << "queue is full" << std::endl;
		return;
	}
	if(++_tail == _capacity){
		_tail = 0;
	}
	data[_tail] = x;
	++_size;
}

int Queue::poll(){
	if(isEmpty()){
		std::cerr << "queue is empty" << std::endl;
		return -1;
	}
	int val = data[_head];
	if(++_head == _capacity){
		_head = 0;
	}
	--_size;
	return val;
}

void Queue::print(){
	if(_size > 0){
		int i;
		for (i = _head; i != _tail;) {
			std::cout << data[i] << '\t' ;
			++i;
			if (i == _capacity) {
				i = 0;
			}
		}
		std::cout << data[i] << '\t' << std::endl;
	}
}
