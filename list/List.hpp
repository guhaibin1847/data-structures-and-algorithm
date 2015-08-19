/*
 * list.h
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */

#ifndef LIST_HPP_
#define LIST_HPP_
#include <iostream>
#include "ListNode.hpp"

class List {
public :
	List():head(new ListNode()){}
	List(const List& list);
	List& operator=(const List& list);
	~List();
	/************ list operator *********/
	void add_back(int x);//在链表尾部插入x
	void add_front(int x);
	void add(int e, int x);//在e后面插入x
	ListNode* find_previous(int x);//找到值为x的节点的前一个节点
	bool remove(int x);
	ListNode* find(int x);
	void print();
private :
	ListNode *head;
};



#endif /* LIST_HPP_ */
