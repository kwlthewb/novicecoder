/*
 * cat.h
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#ifndef CAT_H_
#define CAT_H_
#include "Incls.h"
#include "Singleton.h"

class cat {
std::string _name;
public:
	cat(char* name);
	~cat();
	void meow();
};

#endif /* CAT_H_ */
