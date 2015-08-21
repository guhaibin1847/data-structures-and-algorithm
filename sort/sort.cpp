/*
 * sort.cpp
 *
 *  Created on: 2015年8月20日
 *      Author: bean
 */
#include <iostream>
#include <queue>
#include <utility>
#include "sort.hpp"

void print(int A[], int n){
	if(A != nullptr && n > 0){
		for(int i = 0 ; i < n ; ++i){
			std::cout << A[i] << '\t';
		}
	}
	std::cout << std::endl;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertSort(int A[], int n){
	std::cout << "Before Insert Sort:\t";
	print(A, n);
	if(A != nullptr && n > 1){
		int i , j ;
		for(i = 1 ; i < n ; ++i){
			int tmp = A[i];
			for(j = i ; j > 0 && tmp < A[j - 1] ; --j){
				A[j] = A[j - 1];
			}
			A[j] = tmp;
		}
	}
	std::cout << "After Insert Sort:\t";
	print(A, n);

}


void shellSort(int A[], int n){
	std::cout << "Before Shell Sort:\t";
	print(A, n);
	if(A != nullptr && n > 1){
		int i , j , increment, tmp;
		for(increment = n / 2 ; increment > 0 ; increment /= 2){
			for(i = increment ; i < n ; ++i){
				tmp = A[i];
				for(j = i ; j >= increment && tmp < A[j - increment]; j -= increment){
					A[j] = A[j - increment];
				}
				A[j] = tmp;
			}
		}
	}
	std::cout << "After Shell Sort:\t";
	print(A, n);
}

void selectSort(int A[], int n){
	if(A != nullptr && n > 1){
		std::cout << "Before Select Sort:\t";
		print(A, n);
		for(int i = 0 ; i < n ; ++i){
			int min = A[i];
			int k = i;
			for(int j = i + 1 ; j < n ; ++j){
				if(A[j] < min){
					min = A[j];
					k = j;
				}
			}
			if(k != i)
				swap(&A[i], &A[k]);
		}
		std::cout << "After Select Sort:\t";
		print(A, n);
	}
}

void bubbleSort(int A[], int n){
	if(A != nullptr && n > 1){
		std::cout << "Before Bubble Sort:\t";
		print(A, n);
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n - i - 1 ; ++j){
				if(A[j] > A[j + 1]){
					swap(&A[j], &A[j+1]);
				}
			}
		}
		std::cout << "After Bubble Sort:\t";
		print(A, n);
	}
}

/************* heap sort ****************/
void percolateDown(int A[], int i , int n){
	int tmp = A[i];
	int child;
	for(; 2 * i < n ; i = child){
		child = 2 * i;
		if(child != n-1 && A[child + 1] > A[child]){
			++child;
		}
		if(tmp < A[child]){
			A[i] = A[child];
		}else {
			break;
		}
	}
	A[i] = tmp;
}



void heapSort(int A[], int n){
	std::cout << "Before Heap Sort:\t";
	print(A, n);
	for(int i = n/2 ; i > 0 ; --i){
		percolateDown(A, i, n);
	}
	print(A, n);
	for(int i = n-1 ; i > 0 ; --i){
		swap(&A[1], &A[i]);
		percolateDown(A, 1, i);
	}
	std::cout << "After Heap Sort:\t";
	print(A, n);
}

/******************* merge sort *****************/
void merge(int A[], int tmp[], int left, int right , int rightEnd){
	int length = rightEnd - left + 1;
	int leftEnd = right -1;
	int tmpPos = left;
	while(left <= leftEnd && right <= rightEnd){
		if(A[left] < A[right]){
			tmp[tmpPos++] = A[left++];
		}else {
			tmp[tmpPos++] = A[right++];
		}
	}
	while(left <= leftEnd){
		tmp[tmpPos++] = A[left++];
	}
	while(right <= rightEnd){
		tmp[tmpPos++] = A[right++];
	}
	for(int i = 0 ; i < length ; ++i){
		A[rightEnd] = tmp[rightEnd];
		--rightEnd;
	}
}

void msort(int A[], int tmp[], int begin, int end){
	if(begin < end){
		int mid = (begin + end) / 2;
		msort(A, tmp, begin, mid);
		msort(A, tmp, mid+1, end);
		merge(A, tmp, begin, mid+1, end);
	}
}

void mergeSort(int A[] , int n){
	if(A != nullptr && n > 1){
		std::cout << "Before MergeSort Sort:\t";
		print(A, n);
		int *tmp = new int[n];
		msort(A, tmp, 0, n-1);
		delete [] tmp;
		std::cout << "After MergeSort Sort:\t";
		print(A, n);
	}
}

std::vector<int> merge(std::vector<int> one, std::vector<int> two){
	int aLen = one.size();
	int bLen = two.size();
	std::vector<int> c;
	int i = 0 , j = 0;
	while(i < aLen && j < bLen){
		if(one[i] < two[j]){
			c.push_back(one[i++]);
		}else {
			c.push_back(two[j++]);
		}
	}
	while(i < aLen){
		c.push_back(one[i++]);
	}
	while(j < bLen){
		c.push_back(two[j++]);
	}
	return c;
}

void mergeSortIterative(int A[], int n){
	if(A != nullptr && n > 1){
		std::cout << "Before MergeSort Sort:\t";
		print(A, n);
		std::queue<std::vector<int>> q;
		for(int i = 0 ; i < n ; ++i){
			std::vector<int> v;
			v.push_back(A[i]);
			q.push(v);
		}
		while(q.size() > 1){
			std::vector<int> one = q.front();
			q.pop();
			std::vector<int> two = q.front();
			q.pop();
			std::vector<int> m = merge(one, two);
			q.push(m);
		}
		std::vector<int> t = q.front();
		for(int i = 0 ; i < n ; ++i){
			A[i] = t[i];
		}
		std::cout << "After MergeSort Sort:\t";
		print(A, n);
	}
}

/******************** quick sort *********************/
int partition(int A[], int begin, int end){
	int tmp = A[begin];
	int i = begin, j = end;
	while(i < j){
		while(i < j && A[j] > tmp){
			--j;
		}
		if(i < j){
			A[i] = A[j];
			++i;
		}
		while(i < j && A[i] < tmp){
			++i;
		}
		if(i < j){
			A[j] = A[i];
			--j;
		}
	}
	A[i] = tmp;
	return i;
}

void _qsort(int A[], int begin, int end){
	if(begin < end){
		int index = partition(A, begin, end);
		_qsort(A, begin, index);
		_qsort(A, index+1, end);
	}
}

void quickSort(int A[], int n){
	if(A != nullptr && n > 1){
		std::cout << "Before QuickSort Sort:\t";
		print(A, n);
		_qsort(A, 0, n-1);
		std::cout << "After QuickSort Sort:\t";
		print(A, n);
	}
}
























