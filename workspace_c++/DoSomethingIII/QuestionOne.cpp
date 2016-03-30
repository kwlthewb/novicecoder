/*
 * QuestionOne.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: bill
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

//int solution(vector<int> &A) {
//	long count = 0;
//	long idx = 0;
//	while(count < A.size()) { // ensure we don't count more than the size of array
//		//std::cout << idx << "," << A[idx] << std::endl;
//		count++;
//		if((long) A[idx] == -1)
//			return count;
//		idx = A[idx];
//	}
//	return count;
//}

//int solution(int A, int B) {
//	long long count = 0;
//	long long root = 0;
//	for(long long i = A; i <= B; i++) {
//		if (i > 0) {
//			root = (long long) round(sqrtl((long long)i));
//			if((root * root) == i) {
//				count++;
//				std::cout << i << "," << root * root << ",root," << root << "," << count << std::endl;
//			}
//		}
//	}
//	return count;
//}

//long double factorial(long long v) {
//	if (v == 0)
//		return 1;
//	long double total = 1;
//	for(long long i = 1; i <= v; i++) {
//		total *= i;
//		std::cout << "i," << i << " = " << total << std::endl;
//	}
//	std::cout << "Fact," << v << " = " << total << std::endl;
//	return total;
//}
//
//int solution(int N, int K) {
//	if(K > N || N < 0 || K < 0)
//		return -1;
//    long double fact = 0;
//    long double benchmark = 1000000000;
//    fact = (long double) factorial(N) / (factorial(K) * factorial(N - K));
//    std::cout << "N,K:" << N << "," << K << " => " << fact << std::endl;
//    if(fact > benchmark)
//    	return -1;
//    return fact;
//}

//std::map<std::pair<int, int>, long long> spiral;
//std::map<std::pair<int, int>, long long>::iterator itr;
//
//void constructSpiral() {
//	int smallX = 0, smallY = 0;
//	int downLegX = 2, upLegX = 1, startIdx, endIdx;
//	int clockDir = 0; // 0 - go north, 1 - go east, 2 - go south, 3 - go north
//
//	long long count = 0;
//	while(smallX > -20010 && smallY > -20010) {
//		// next point
//		switch(clockDir) {
//		case 0: // head north by upLegX number of points
//			startIdx = smallY;
//			endIdx = smallY + upLegX;
//			for(int i = startIdx; i < endIdx; i++) {
//				smallY += 1;
//				count++;
//				//std::cout << "N," << smallX << "," << smallY << "," << count << std::endl;
//				spiral.insert(std::make_pair(std::make_pair(smallX,smallY),count));
//			}
//			clockDir = 1;
//			break;
//		case 1: // head east by upLegX number of points
//			startIdx = smallX;
//			endIdx = smallX + upLegX;
//			for(int i = startIdx; i < endIdx; i++) {
//				smallX += 1;
//				count++;
//				//std::cout << "E," << smallX << "," << smallY << "," << count << std::endl;
//				spiral.insert(std::make_pair(std::make_pair(smallX,smallY),count));
//			}
//			clockDir = 2;
//			break;
//		case 2: // head south by upLegX number of points
//			startIdx = smallY;
//			endIdx = smallY + (downLegX * -1);
//			for(int i = startIdx; i > endIdx; i--) {
//				smallY -= 1;
//				count++;
//				//std::cout << "S," << smallX << "," << smallY << "," << count << std::endl;
//				spiral.insert(std::make_pair(std::make_pair(smallX,smallY),count));
//			}
//			clockDir = 3;
//			break;
//		case 3: // head west by upLegX number of points
//			startIdx = smallX;
//			endIdx = smallX + (downLegX * -1);
//			for(int i = startIdx; i > endIdx; i--) {
//				smallX -= 1;
//				count++;
//				//std::cout << "W," << smallX << "," << smallY << "," << count << std::endl;
//				spiral.insert(std::make_pair(std::make_pair(smallX,smallY),count));
//			}
//			// loop back and increase multipliers
//			clockDir = 0;
//			upLegX += 2;
//			downLegX += 2;
//			break;
//		}
//	}
//}
//
//int solution(int X, int Y) {
//	itr = spiral.find(std::make_pair(X,Y));
//	if(itr != spiral.end())
//		return itr->second;
//	return -1;
//}

int solution(int X, int Y) {
	// construct the spiral until x,y coordinates go beyong -20000,-20000
	int smallX = 0, smallY = 0;
	int downLegX = 2, upLegX = 1, startIdx, endIdx;
	int clockDir = 0; // 0 - go north, 1 - go east, 2 - go south, 3 - go north

	int count = 0;
	std::map<std::pair<int, int>, int> spiral;
	while(smallX > -20010 && smallY > -20010) {
		if(smallX == X && smallY == Y)
			return count;
		// next point
		switch(clockDir) {
		case 0: // head north by upLegX number of points
			startIdx = smallY;
			endIdx = smallY + upLegX;
			for(int i = startIdx; i < endIdx; i++) {
				smallY += 1;
				count++;
				std::cout << "N," << smallX << "," << smallY << "," << count << std::endl;
				if(smallX == X && smallY == Y)
					return count;
			}
			clockDir = 1;
			break;
		case 1: // head east by upLegX number of points
			startIdx = smallX;
			endIdx = smallX + upLegX;
			for(int i = startIdx; i < endIdx; i++) {
				smallX += 1;
				count++;
				std::cout << "E," << smallX << "," << smallY << "," << count << std::endl;
				if(smallX == X && smallY == Y)
					return count;
			}
			clockDir = 2;
			break;
		case 2: // head south by upLegX number of points
			startIdx = smallY;
			endIdx = smallY + (downLegX * -1);
			for(int i = startIdx; i > endIdx; i--) {
				smallY -= 1;
				count++;
				std::cout << "S," << smallX << "," << smallY << "," << count << std::endl;
				if(smallX == X && smallY == Y)
					return count;
			}
			clockDir = 3;
			break;
		case 3: // head west by upLegX number of points
			startIdx = smallX;
			endIdx = smallX + (downLegX * -1);
			for(int i = startIdx; i > endIdx; i--) {
				smallX -= 1;
				count++;
				std::cout << "W," << smallX << "," << smallY << "," << count << std::endl;
				if(smallX == X && smallY == Y)
					return count;
			}
			// loop back and increase multipliers
			clockDir = 0;
			upLegX += 2;
			downLegX += 2;
			break;
		}
	}
	return -1;
}
int main_func2() {
//	std::vector<int> a;
//	a.push_back(1); // 0
//	a.push_back(4); // 1
//	a.push_back(3); // 2
//	a.push_back(6); // 3
//	a.push_back(2); // 4
//	a.push_back(3); // 5
//	a.push_back(-1); // 6
//
	//constructSpiral();
	cout << solution(-1,2) << std::endl;
}
