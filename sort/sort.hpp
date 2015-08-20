/*
 * sort.hpp
 *
 *  Created on: 2015年8月20日
 *      Author: bean
 */

#ifndef SORT_HPP_
#define SORT_HPP_

void print(int A[], int n);

/*
 * 各类排序总结
 * 排序方法			平均复杂度		最坏复杂度	 辅助空间		稳定性
 *
 * 直接插入排序		  O(n2)			O(n2)			O(1)		稳定
 * shell排序			  O(n1.3)		O(n2)			O(1)		不稳定
 * 直接选择排序		  O(n2)			O(n2)			O(1)		不稳定
 * 堆排序			  O(nlogn)		O(nlogn)		O(1)		不稳定
 * 冒泡排序			  O(n2)			O(n2)			O(1)		稳定
 * 快速排序			  O(nlogn)		O(n2)			O(nlogn)	不稳定
 * 归并排序			  O(nlogn)		O(nlogn)		O(n)		稳定
 *
 */

/*插入排序*/
void insertSort(int A[], int n);
void shellSort(int A[], int n);
/*选择排序*/
void selectSort(int A[], int n);
void heapSort(int A[], int n);
/*交换排序*/
void bubbleSort(int A[], int n);
void quickSort(int A[], int n);
/*归并排序*/
void mergeSort(int A[], int n);




#endif /* SORT_HPP_ */
