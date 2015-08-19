/*
 * ListNode.h
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */

#ifndef LISTNODE_HPP_
#define LISTNODE_HPP_

class ListNode {
public :
	ListNode():_val(0), _next(nullptr){}
	ListNode(int val):_val(val), _next(nullptr){}
	ListNode(int val, ListNode *next):_val(val), _next(next){}
	ListNode(const ListNode &node):_val(node._val), _next(node._next){}
	ListNode & operator=(const ListNode &node){
		_val = node._val;
		_next = node._next;
		return *this;
	}
	~ListNode(){
		if(_next != nullptr){
			delete _next;//循环调用，直到_next == nullptr
		}
	}
	ListNode* next(){return _next;}
	void setNext(ListNode *next){ this->_next = next;}
	int val(){return _val;}
private:
	int _val;
	ListNode *_next;
};




#endif /* LISTNODE_HPP_ */
