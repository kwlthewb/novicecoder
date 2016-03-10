/*
 * Singleton.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "Singleton.h"

dog* Singleton::pd = 0;
cat* Singleton::pc = 0;

dog* Singleton::getDog() {
	if(!pd) {
		std::cout << "Dog is created." << std::endl;
		pd = new dog("Gunner");
	}
	return pd;
}

cat* Singleton::getCat() {
	if(!pc) {
		std::cout << "Cat is created." << std::endl;
		pc = new cat("Smokey");
	}
	return pc;
}

Singleton::~Singleton() {
	if(pd) {
		delete pd;
		std::cout << "Dog is destroyed." << std::endl;
	}
	if(pc) {
		delete pc;
		std::cout << "Cat is destroyed." << std::endl;
	}
	pd = 0;
	pc = 0;
}

void scope() {
	Singleton s;
	dog* pd = s.getDog();
	pd->bark();
//	cat* pc = s.getCat();
//	pc->meow();
	dog* pd2 = s.getDog();
	pd2->bark();
//	cat* pc2 = s.getCat();
//	pc2->meow();
	dog* pd3 = s.getDog();
	pd3->bark();
//	cat* pc3 = s.getCat();
//	pc3->meow();

}

int main() {
	scope();
}
