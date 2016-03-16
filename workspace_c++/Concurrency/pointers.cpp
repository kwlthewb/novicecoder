/*
 * pointers.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: bill
 */

#include "pointers.h"

struct A {
	A() : int_ptr_(new int) {}
	~A() {
		std::cout << "Delete pointer" << std::endl;
		//delete int_ptr_;
	}
private:
	//int *int_ptr_;
	boost::scoped_ptr<int> int_ptr_;
};

namespace ppp {
class Dog{
	std::string m_name;
public:
	Dog(std::string n) : m_name(n) {
		std::cout << "Dog is created: " << m_name << std::endl;
	}
	Dog() {
		m_name = "";
		std::cout << "Dog is created: nameless\n";
	}
	~Dog() {
		std::cout << "Dog is destroyed: " << m_name << std::endl;
	}
	void bark() {
		std::cout << "Dog " << m_name
	}
};

}


int main_func() {
	int* int_ptr2 = new int;
	int* int_ptr;
	int i = 456;
	int_ptr = &i;
	*int_ptr2 = 2221212;
	std::cout << *int_ptr2 << std::endl;
	i = 999;
	*int_ptr2 = 99999;
	std::cout << *int_ptr2 << std::endl;
	delete int_ptr2;
	return 0;
}
