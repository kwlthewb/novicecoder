/*
 * cat.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "cat.h"
#include "dog.h"
#include "Singleton.h"

class Singleton;

cat::cat(char* name) {
	_name = name;
	std::cout << _name << " cat is born." << std::endl;
	Singleton::getDog()->bark();
}
cat::~cat() { std::cout << _name << " is destroyed" << std::endl; }
void cat::meow() {
	std::cout << "Cat name is " << _name << std::endl;
}
