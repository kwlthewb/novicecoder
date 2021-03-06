/*
 * Casting.h
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */

#ifndef CASTING_H_
#define CASTING_H_
#include "Incls.h"
#include "VirtConst.h"

namespace Casting {

class dog {
public:
	virtual ~dog() {}
	virtual void bark() { std::cout << "Do something" << std::endl; };
};

class yellowdog : public dog {
	int age;
public:
	virtual void bark() { std::cout << "woof...woof.." << age << std::endl; }
};


} /* namespace Casting */

#endif /* CASTING_H_ */
