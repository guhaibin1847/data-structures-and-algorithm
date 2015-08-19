/*
 * maim.cpp
 *
 *  Created on: 2015年8月17日
 *      Author: bean
 */

#include <iostream>
#include "stack.hpp"

int main(){
	Stack s ;
	s.push(1);
	s.push(2);
	s.push(3);
	int x = s.top();
	std::cout << x << '\t' << std::endl;
	s.pop();
	x = s.top();
	std::cout << x << '\t' << std::endl;
	Stack s2(s);
	s.pop();
	x = s2.top();
	std::cout << x << '\t' << std::endl;
	return 0;
}


