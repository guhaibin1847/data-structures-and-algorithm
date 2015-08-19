/*
 * stack.cpp
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */
#include <iostream>
#include <exception>
#include "stack.hpp"

//实行深拷贝
Stack::Stack(const Stack& stack):_top(nullptr), size(stack.size){
	_top = new Node(stack._top->_val);
	Node *t = _top;
	Node *p = stack._top->_next;
	while(p != nullptr){
		t->_next = new Node(p->_val);
		p = p->_next;
		t = t->_next;
	}
}

Stack& Stack::operator=(const Stack &stack){
	if(this != &stack){
		Stack tmp(stack);
		Node *tp = tmp._top;
		tmp._top = this->_top;
		this->_top = tp;
		this->size = tmp.size;
	}
	return *this;
}

Stack::~Stack(){
	delete _top;
}

void Stack::push(int x){
	Node *p = new Node(x);
	p->_next = _top;
	_top = p;
	++size;
}

void Stack::pop(){
	if(!isEmpty()){
		Node *tmp = _top;
		_top = _top->_next;
		tmp->_next = nullptr;
		delete tmp;
		--size;
	}else {
		std::cerr << "stack is empty" << std::endl;
	}
}

int Stack::top(){
	if(!isEmpty()){
		return _top->_val;
	}else {
		std::cerr << "stack is empty" << std::endl;
		return -1;
	}
}

int Stack::topAndPop(){
	if(!isEmpty()){
		int val = this->top();
		this->pop();
		return val;
	}else {
		std::cerr << "stack is empty" << std::endl;
		return -1;
	}
}












