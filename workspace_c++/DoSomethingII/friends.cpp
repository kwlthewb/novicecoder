/*
 * friends.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: bill
 */

#include "friends.h"

namespace A {
class Rectangle {
	int width, height;
public:
	Rectangle() : width(0), height(0) {
		std::cout << "Rectangle created, " << width << " x " << height << "\n";
	}
	Rectangle(int x, int y) : width(x), height(y) {
		std::cout << "Rectangle created, " << width << " x " << height << "\n";
	}
	~Rectangle() {
		std::cout << "Rectangle destroyed, " << width << " x " << height << "\n";
	}
	int area() { return width * height; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	friend Rectangle duplicate(const Rectangle& param);
};

Rectangle duplicate(const Rectangle& param) {
	Rectangle res(param.width, param.height);
	return res;
}
};

int main_func6() {
	A::Rectangle foo;
	A::Rectangle bar(5,9);
	std::string strAry[1000000];
	std::string *strAry2 = new std::string[8];
	for(int i = 0; i < 8; i++) {
		*(strAry2 + i) = "test";
	}
	for(int i = 0; i < 8; i++) {
		std::cout << i << "," << *(strAry2+i) << std::endl;
	}
	srand(time(NULL));
	A::Rectangle *rectAry = new A::Rectangle[10];
	int h,w;
	for(int i = 0; i < 10; i++) {
		w = rand() % 25;
		h = rand() % 25;
		(rectAry + i)->setWidth(rand() % 25);
		(*(rectAry + i)).setHeight(rand() % 25);
	}
	for(int i = 0; i < 10; i++) {
		std::cout << i << "," << (*(rectAry + i)).area() << ","
				<< (rectAry + i)->getWidth() << ","
				<< (*(rectAry + i)).getHeight() << std::endl;
	}

	std::cout << "foo: " << foo.getWidth() << " x " << foo.getHeight() << std::endl;
	std::cout << "bar: " << bar.getWidth() << " x " << bar.getHeight() << std::endl;
	foo = A::duplicate(bar);
	std::cout << "foo: " << foo.getWidth() << " x " << foo.getHeight() << std::endl;
	std::cout << "bar: " << bar.getWidth() << " x " << bar.getHeight() << std::endl;
	std::cout << sizeof(strAry) << std::endl;
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	std::cout << "Start time = " << currentDateTime() << std::endl;
	Sleep(10000);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - begin;
	std::cout << "End   time = " << currentDateTime() << " " << diff.count() << std::endl;

}
