/*
 * LIS.cpp
 * 最长递增子序列
 * 问题描述：给定一个数字序列A及序列的长度n，请返回最长上升子序列的长度
 * 测试样例：
 * [2,1,4,3,1,5,6],7
 * 返回：4
 *  Created on: 2015年8月26日
 *      Author: bean
 */
#include <iostream>

int lis(int A[], int n){
	if(A == nullptr || n <= 0){
		return -1;
	}
	int *tmp = new int[n];
	for(int i = 0 ; i < n ; ++i){
		tmp[i] = 1;
	}
	for(int i = 1 ; i < n ; ++i){
		for(int j = 0 ; j < i ; ++j){
			if(A[i] > A[j] && tmp[i] < tmp[j] + 1){
				tmp[i] = tmp[j] + 1;
			}
		}
	}
	int max = 0;
	for(int i = 0 ; i < n ; ++i){
		if(max < tmp[i]){
			max = tmp[i];
		}
	}
	delete [] tmp;
	return max;
}

int main(){
	int A[6] = {168,92,273,36,222,146};
	int max = lis(A, 6);
	std::cout << "max : " << max << std::endl;
	return 0;
}



