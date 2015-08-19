/*
 * queue.hpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#define DEFAULT_QUEUE_CAPACITY 10

class Queue {
public :
	Queue():_capacity(DEFAULT_QUEUE_CAPACITY), _size(0), _head(0), _tail(-1), data(new int[DEFAULT_QUEUE_CAPACITY]){}
	Queue(int capacity):_capacity(capacity), _size(0), _head(0), _tail(-1), data(new int[capacity]){}
	Queue(const Queue &queue);
	Queue& operator=(const Queue &queue);
	~Queue(){
		if(data != nullptr){
			delete[] data;
			data = nullptr;
		}
	}

	void offer(int x);
	int poll();
	int size(){
		return _size;
	}
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
	int _head;
	int _tail;
	int *data;
};



#endif /* QUEUE_HPP_ */
