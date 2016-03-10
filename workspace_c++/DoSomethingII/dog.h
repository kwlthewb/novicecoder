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
	dog(char* name);
	~dog();
	void bark();
	int getCount();
};

#endif /* DOG_H_ */