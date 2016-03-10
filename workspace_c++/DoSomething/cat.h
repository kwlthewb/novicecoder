/*
 * cat.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */
#include "Incls.h"
#include "dog.h"
#include "Singleton.h"

//extern dog d;

class cat {
	std::string _name;
public:
	cat(char* name) {
		_name = name;
		std::cout << _name << " cat is born." << std::endl;
		//Singleton::getDog()->bark();
	}
	~cat() { std::cout << _name << " is destroyed" << std::endl; }
	void meow() {
		std::cout << "Cat name is " << _name << std::endl;
	}
};

