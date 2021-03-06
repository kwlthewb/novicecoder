/*
 * VirtualTest.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "VirtualTest.h"
#include "Incls.h"

VirtualTest::VirtualTest() {
	// TODO Auto-generated constructor stub

}

VirtualTest::~VirtualTest() {
	// TODO Auto-generated destructor stub
}

class collar {
public:
	collar() { std::cout << "collar is tugged" << std::endl; }
};

class DDog {
public:
	collar* pCollar;
	DDog& operator=(const DDog& rhs) {
		if(this == &rhs) // check if copying self
			return *this;
		collar* pOrigCollar = pCollar;
		pCollar = new collar(*rhs.pCollar);
		delete pOrigCollar;
		return *this;
	}
//	DDog& operator=(const DDog& rhs) {
//		*pCollar = *rhs.pCollar;
//		return *this;
//	}

	DDog() { std::cout << "Dog born." << std::endl; bark(); }
	~DDog() { std::cout << "Dog destroyed." << std::endl; }
	virtual void bark() { std::cout << "I am just a dog." << std::endl; }
	void seeCat() { bark(); }
};

class YDog : public DDog {
public:
	YDog() { std::cout << "Yellow dog is born." << std::endl; }
	~YDog() { std::cout << "Yellow dog is destroyed." << std::endl; }
	void bark() { std::cout << "I am a yellow dog." << std::endl; }
};

int main_func3() {
	YDog d;
	d.seeCat();
	return 0;
}


