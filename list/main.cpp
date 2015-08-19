/*
 * main.cpp
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */

#include "List.hpp"

int main(){
	List list;
	list.add_back(1);
	list.add_back(2);
	list.add_back(3);
	list.add_front(4);
	list.print();
	list.remove(5);
	list.remove(3);
	list.print();
	List list2(list);
	list2.print();
	list2.add(1, 5);
	list.print();
	list2.print();
	return 0;
}


