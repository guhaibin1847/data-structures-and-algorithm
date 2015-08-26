/*
 * findLongest.cpp
 *
 *  Created on: 2015年8月26日
 *      Author: bean
 */
#include <iostream>
#include <string>
using std::string;

int findLongestSubstring(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	if(n == 0 || m == 0){
		return 0;
	}
	int max[50][50] = {0};
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1; j <= m ; ++j){
			if(s1[i-1] == s2[j-1]){
				max[i][j] = max[i-1][j-1] + 1;
			}
		}
	}
	int res = 0;
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j <= m ; ++j){
			if(res < max[i][j]){
				res = max[i][j];
			}
			std::cout << max[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	return res;
}

int main(){
	string s1 = "bab";
	string s2 = "caba";
	int max = findLongest(s1, s2);
	std::cout << max << std::endl;
	return 0;
}

