/*
 * Singleton.h
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include "Incls.h"
#include "cat.h"
#include "dog.h"

class cat;
class dog;

class Singleton {
	static dog* pd;
	static cat* pc;
public:
	Singleton() {};
	~Singleton();
	static dog* getDog();
	static cat* getCat();
};

#endif /* SINGLETON_H_ */
