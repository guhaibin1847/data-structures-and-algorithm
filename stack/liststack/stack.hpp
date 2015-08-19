/*
 * stack.hpp
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */

#ifndef STACK_HPP_
#define STACK_HPP_

struct Node {
	int _val;
	struct Node* _next;
	Node(int val, struct Node* next):_val(val), _next(next){}
	Node(int val):_val(val), _next(nullptr){}
	~Node(){
		if(_next != nullptr){
			delete _next;
		}
	}
};

class Stack {
public :
	Stack():_top(nullptr), size(0){}
	Stack(const Stack& stack);
	Stack& operator=(const Stack& stack);
	~Stack();
	void push(int x);
	int top();
	void pop();
	int topAndPop();
	bool isEmpty(){
		return size == 0;
	}
private :
	struct Node *_top;
	int size;
};



#endif /* STACK_HPP_ */
