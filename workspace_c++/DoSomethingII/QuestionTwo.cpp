/*
 * QuestionTwo.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: bill
 */

#include "QuestionTwo.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstddef>

bool overlapRect(const std::string &text) {
	std::vector<int> coords;

	std::size_t start = 0, end = 0;
	while ((end = text.find(' ', start)) != std::string::npos) {
		std::string temp = text.substr(start, end - start);
		if (temp != "") coords.push_back(atoi(temp.c_str()));
		start = end + 1;
	}
	std::string temp = text.substr(start);
	if (temp != "") coords.push_back(atoi(temp.c_str()));

	int x1 = coords[0];
	int y1 = coords[1];
	int w1 = coords[2];
	int h1 = coords[3];
	int x2 = coords[4];
	int y2 = coords[5];
	int w2 = coords[6];
	int h2 = coords[7];

//	std::cout << "x1," << x1 << std::endl;
//	std::cout << "y1," << y1 << std::endl;
//	std::cout << "w1," << w1 << std::endl;
//	std::cout << "h1," << h1 << std::endl;
//	std::cout << "x2," << x2 << std::endl;
//	std::cout << "y2," << y2 << std::endl;
//	std::cout << "w2," << w2 << std::endl;
//	std::cout << "h2," << h2 << std::endl;

	// Construct the two rectangles
	std::vector<std::pair<int, int>> rect1;
	std::vector<std::pair<int, int>>::iterator rect1Itr;
	std::vector<std::pair<int, int>> rect2;
	std::vector<std::pair<int, int>>::iterator rect2Itr;
	// first rectangle
	for(int i = x1; i <= x1 + w1; i++) { // width
		for(int j = y1; j <= y1 + h1; j++) { // height
			//std::cout << i << "," << j << std::endl;
			rect1.push_back(std::make_pair(i,j));
		}
	}
	// second rectangle
	for(int i = x2; i <= x2 + w2; i++) { // width
		for(int j = y2; j <= y2 + h2; j++) { // height
			//std::cout << i << "," << j << std::endl;
			rect2.push_back(std::make_pair(i,j));
		}
	}

//	for(rect1Itr = rect1.begin(); rect1Itr != rect1.end(); rect1Itr++) {
//		std::cout << "Rect1," << rect1Itr->first << "," << rect1Itr->second << std::endl;
//	}
//	for(rect2Itr = rect2.begin(); rect2Itr != rect2.end(); rect2Itr++) {
//		std::cout << "Rect2," << rect2Itr->first << "," << rect2Itr->second << std::endl;
//	}
	for(rect1Itr = rect1.begin(); rect1Itr != rect1.end(); rect1Itr++) {
		for(rect2Itr = rect2.begin(); rect2Itr != rect2.end(); rect2Itr++) {
			if(rect1Itr->first == rect1Itr->first && rect1Itr->second == rect2Itr->second) {
				return true;
			}
		}
	}
	return false;
}

int main_func7() {
	std::string line;
	line = "test";
	std::cout << line << std::endl;
	line.append("test");
	std::cout << line << std::endl;
	return 0;
	while(std::getline(std::cin,line)) {

		std::cout << overlapRect(line) << std::endl;
	}

}

