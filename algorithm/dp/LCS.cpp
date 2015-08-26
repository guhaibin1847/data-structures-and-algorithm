/*
 * LCS.cpp
 * 最长公共子序列
 * 给定两个字符串A和B，同时给定两个串的长度n和m，请返回最长公共子序列的长度
 * 测试样例:
 * "1A2C3D4B56",10,"B1D23CA45B6A",12
 * 返回：6
 *  Created on: 2015年8月26日
 *      Author: bean
 */
#include <iostream>
#include <string>
using std::string;

int lcs(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	if(n == 0 || m == 0){
		return 0;
	}
	int max[100][100] = {0};
	for(int i = 0 ; i <= n ; ++i){
		max[i][0] = 0;
	}
	for(int j = 0 ; j <= m ; ++j){
		max[0][j] = 0;
	}

	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(s1[i-1] == s2[j-1]){
				max[i][j] = max[i-1][j-1] + 1;
			}else {
				if(max[i-1][j] > max[i][j-1]){
					max[i][j] = max[i-1][j];
				}else {
					max[i][j] = max[i][j-1];
				}
			}
		}
	}

	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j <= m ; ++j){
			std::cout << max[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	return max[n][m];
}

int main(){
	string s1 = "zynnqufc";
	string s2 = "ddbauhkw";
	int max = lcs(s1, s2);
	std::cout << "lcs : " << max << std::endl;
	return 0;
}
