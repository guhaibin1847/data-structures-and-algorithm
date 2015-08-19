/*
 * List.cpp
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */
#include "List.hpp"

//执行深拷贝
List::List(const List& list):head(new ListNode()){
	ListNode *p = head;
	ListNode *cp = list.head->next();
	while(cp != nullptr){
		ListNode *tmp = new ListNode(cp->val());
		p->setNext(tmp);
		p = p->next();
		cp = cp->next();
	}
}

List& List::operator =(const List& list){

	return *this;
}

List::~List(){
	/*
	ListNode *p = head->next();
	while(p != nullptr){
		ListNode *tmp = p->next();
		delete p;
		p = tmp;
	}
	*/
	delete head;//触发listNode的析构函数进行递归析构
}

void List::add_back(int x){
	ListNode *p = head;
	while(p->next() != nullptr){
		p = p->next();
	}
	ListNode *tmp = new ListNode(x);
	p->setNext(tmp);
}

void List::add_front(int x){
	ListNode *next = head->next();
	ListNode *tmp = new ListNode(x);
	head->setNext(tmp);
	tmp->setNext(next);
}

ListNode* List::find_previous(int x){
	ListNode *p = head;
	while(p->next() != nullptr && p->next()->val() != x){
		p = p->next();
	}
	if(p->next() == nullptr){
		return nullptr;
	}
	return p;
}

ListNode* List::find(int x){
	ListNode *p = head;
	while(p != nullptr && p->val() != x){
		p = p->next();
	}
	return p;
}

void List::add(int e, int x){
	ListNode* previous = find_previous(e);
	if(previous){
		ListNode *tmp = new ListNode(x);
		tmp->setNext(previous->next());
		previous->setNext(tmp);
	}
}
//成功删除返回true，否则返回false
bool List::remove(int x){
	ListNode *pre = find_previous(x);
	if(pre){
		pre->setNext(pre->next()->next());
		return true;
	}
	return false;
}

void List::print(){
	ListNode *p = head->next();
	while(p != nullptr){
		std::cout << p->val() << '\t' ;
		p = p->next();
	}
	std::cout << std::endl;
}





