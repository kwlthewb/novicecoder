/*
 * MainClass.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: bill
 */

#include <stdio.h>
#include <iostream>
#include <vector>

void func() {
	printf("Hello\n");
}

//void func(int a) {
//	printf("Hello2\n");
//}

void func(const int& a) {
	printf("Hello2\n");
}

class HH {
	int m_n;
public:
	HH() : m_n(99) {};
	~HH() { std::cout << "Destroyed!!\n"; }
	void pp() {
		std::cout << this->m_n << std::endl;
		std::cout << (*this).m_n << std::endl;
	}
};

int leftSum(std::vector<int> &A, int start, int end) {
	long long int sum = 0;
	if(end < 0) {
		return 0;
	} else {
		for(int i = 0; i <= end; i++) {
			sum += A[i];
		}
	}
	return sum;
}

int rightSum(std::vector<int> &A, int start, int end) {
	int sum = 0;
	if(start > A.size()) {
		return 0;
	} else {
		for(int i = start; i < A.size(); i++) {
			sum += A[i];
		}
	}
	return sum;
}

int solutionx(std::vector<int> &A) {

	for(uint i = 0; i < A.size(); i++) {
		if(leftSum(A, i - 2, i - 1) == rightSum(A,i+1,A.size())) {
			std::cout << "EQ idx: " << i << std::endl;
			//return i;
		}
	}
	return -1;
}

int main_func() {
	std::vector<int> a;
	a.push_back(0);
	a.push_back(-2147483648);
	a.push_back(-2147483648);
//	a.push_back(-1);
//	a.push_back(3);
//	a.push_back(-4);
//	a.push_back(5);
//	a.push_back(1);
//	a.push_back(-6);
//	a.push_back(2);
//	a.push_back(1);
	std::cout << solutionx(a) << std::endl;


	func();
	func(1);
	HH h;
	h.pp();
}
