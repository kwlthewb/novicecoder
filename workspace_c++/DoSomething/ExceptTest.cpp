/*
 * ExceptTest.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "ExceptTest.h"
#include "Incls.h"
#include "cat.h"
#include "dog.h"
#include "Singleton.h"

ExceptTest::ExceptTest() {
	// TODO Auto-generated constructor stub

}

ExceptTest::~ExceptTest() {
	// TODO Auto-generated destructor stub
}

//class dog {
//	std::string m_name;
//public:
//	dog(std::string name) { m_name = name; std::cout << name << " is born." << std::endl; }
//	~dog() { std::cout << m_name << " is destroyed." << std::endl; }
//	void bark() { std::cout << m_name << " bark bark bark..." << std::endl; }
//	void prepareToDestr() {
//		std::cout << m_name << " prepareToDestr called." << std::endl;
//		throw 20;
//	}
//};


//dog d("Gunner");

int main_func5() {
//	try {
//		dog dog1("Henry");
//		dog dog2("Bob");
//		//throw 20;
//		dog1.bark();
//		dog2.bark();
//		dog1.prepareToDestr();
//		dog2.prepareToDestr();
//	} catch(int e) {
//		std::cout << e << " is caught" << std::endl;
//	}
	//d.bark();
	//std::cout << "Dog count0: " << d.getCount() << std::endl;
	dog dd1("billbear");
	std::cout << "Dog count1: " << dd1.getCount() << std::endl;
	dog dd2("billbear");
	std::cout << "Dog count2: " << dd2.getCount() << std::endl;
	dog dd3("billbear");
	std::cout << "Dog count3: " << dd3.getCount() << std::endl;
	dog dd4("billbear");
	std::cout << "Dog count4: " << dd4.getCount() << std::endl;
	dog dd5("billbear");
	std::cout << "Dog count5: " << dd5.getCount() << std::endl;

	for(int i = 0; i < 50; i++) {
		dog dd("billbear");
		std::cout << "Dog count: " << dd.getCount() << std::endl;
	}

	return 0;
}
