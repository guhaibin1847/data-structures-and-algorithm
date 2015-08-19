/*
 * queue.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#include <iostream>
#include "queue.hpp"

Queue::Queue(const Queue &queue):_size(queue._size), head(nullptr), tail(nullptr){
	Node *h = queue.head;
	if(h != nullptr){
		head = new Node(h->_val);
		if(queue.head == queue.tail){//只有一个节点的情况
			tail = head;
		}else{
			Node *p = head;
			h = h->_next;
			while(h != queue.tail){
				Node *tmp = new Node(h->_val);
				p->_next = tmp;
				h = h->_next;
				p = p->_next;
			}
			tail = new Node(h->_val);
			p->_next = tail;
		}
	}
}

Queue& Queue::operator=(const Queue &queue){
	//copy and swap
	if(this != &queue){
		Queue tmp(queue);
		this->_size = tmp._size;
		Node *tp = tmp.head;
		tmp.head = this->head;
		this->head = tp;
		tp = tmp.tail;
		tmp.tail = this->tail;
		this->tail = tp;
	}
	return *this;
}

Queue::~Queue(){
	if(head != nullptr && tail != nullptr){
		Node *p = head;
		while(p != tail){
			Node *tp = p;
			p = p->_next;
			delete tp;
		}
		delete p;
		head = tail = nullptr;
		_size = 0;
	}
}

void Queue::offer(int x){
	if(isEmpty()){
		tail = new Node(x);
		head = tail;
	}else {
		Node *tp = new Node(x);
		tail->_next = tp;
		tail = tail->_next;
	}
	++_size;
}

int Queue::poll(){
	if(isEmpty()){
		std::cerr << "queue is empty" << std::endl;
		return -1;
	}
	int val = head->_val;
	if(_size == 1){//只有一个节点
		delete head;
		head = tail = nullptr;
	}else {
		Node *tp = head;
		head = head->_next;
		delete tp;
	}
	--_size;
	return val;
}







