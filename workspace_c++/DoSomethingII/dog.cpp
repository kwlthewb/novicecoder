/*
 * dog.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "dog.h"
#include "cat.h"
#include "Singleton.h"

int dog::_count = 0;

dog::dog(char* name) {
	_count += 1;
	_name = name;
	std::cout << _name << " dog is born." << std::endl;
	//Singleton::getCat()->meow();
}
dog::~dog() {
	std::cout << _name << " is destroyed" << std::endl;
}
void dog::bark() { std::cout << "Dog name is " << _name << std::endl; };
int dog::getCount() { return _count; }
