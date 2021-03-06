/*
 * dog.h
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#ifndef DOG_H_
#define DOG_H_
#include "Incls.h"
#include "Singleton.h"

class dog {
	std::string _name;
	static int _count;
public:
	dog(char* name) {
		_count += 1;
		_name = name;
		std::cout << _name << " dog is born." << std::endl;
		//Singleton::getCat()->meow();
	};
	~dog() { std::cout << _name << " is destroyed" << std::endl; }
	void bark() { std::cout << "Dog name is " << _name << std::endl; };
	int getCount() { return _count; }
};

int dog::_count = 0;

#endif /* DOG_H_ */
