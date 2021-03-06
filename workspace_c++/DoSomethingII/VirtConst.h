/*
 * VirtConst.h
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */

#ifndef VIRTCONST_H_
#define VIRTCONST_H_
#include "Incls.h"

namespace VirtConst {

class VirtConst {
public:
	VirtConst();
	virtual ~VirtConst();
};

} /* namespace VirtConst */

namespace VirtConst {

class Dog{
	std::string m_name;
public:
	Dog() { std::cout << "Dog is born." << std::endl; }
	Dog(std::string name) { m_name = name; std::cout << "Dog is born, " << m_name << std::endl; } // constructor plus type converter
	virtual Dog* clone() {
		std::cout << "Dog clone called." << std::endl;
		return (new Dog(*this));
	}
	virtual void bark() { std::cout << "I am a dog." << std::endl; }
	virtual ~Dog() { std::cout << "Dog is destroy." << std::endl; }
};

class Yellowdog: public Dog {
public:
	Yellowdog() { std::cout << "YellowDog is born." << std::endl; }
	virtual Yellowdog* clone() { // co-variant return type
		std::cout << "Yellowdog clone called." << std::endl;;
		return (new Yellowdog(*this));
	}
	virtual void bark() { std::cout << "I am a yellowdog." << std::endl; }
	virtual ~Yellowdog() { std::cout << "YellowDog is destroy." << std::endl; }
};

} /* namespace VirtConst */

#endif /* VIRTCONST_H_ */
