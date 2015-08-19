/*
 * main.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: bean
 */
#include <iostream>
#include "queue.hpp"


int main(){
	Queue q;
	q.offer(1);
	q.offer(2);
	q.offer(3);
	q.offer(4);
	q.offer(5);
	std::cout << "size:" << q.size() << std::endl;
	std::cout << q.poll() << std::endl;
	std::cout << q.poll() << std::endl;
	std::cout << q.poll() << std::endl;
	std::cout << "size:" << q.size() << std::endl;
	q.offer(6);
	q.offer(7);
	q.offer(8);
	q.offer(9);
	q.offer(10);
	q.offer(11);
	std::cout << "size:" << q.size() << std::endl;
	q.print();
	Queue q1(q);
	std::cout << "size:" << q1.size() << std::endl;
	q1.print();
	return 0;
}


