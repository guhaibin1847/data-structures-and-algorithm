/*
 * queue.hpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

struct Node {
	int _val;
	struct Node *_next;
	Node(int val):_val(val),_next(nullptr){}
};

class Queue {
public :
	Queue():_size(0), head(nullptr), tail(nullptr){}
	Queue(const Queue &queue);
	Queue& operator=(const Queue &queue);
	~Queue();
	void offer(int x);
	int poll();
	int size(){
		return _size;
	}
	bool isEmpty(){
		return _size == 0;
	}
private :
	int _size;
	Node *head;
	Node *tail;
};


#endif /* QUEUE_HPP_ */
