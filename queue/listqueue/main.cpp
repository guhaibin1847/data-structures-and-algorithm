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
	std::cout << q.isEmpty() << std::endl;
	q.offer(1);
	q.offer(2);
	q.offer(3);
	q.offer(4);
	q.offer(5);
	std::cout << "size : " << q.size() << std::endl;
	std::cout << q.poll() << std::endl;
	Queue q2(q);//拷贝
	std::cout << q2.poll() << std::endl;
	Queue q3;
	q3 = q2;//赋值
	std::cout << q3.poll() << std::endl;
	return 0;
}
