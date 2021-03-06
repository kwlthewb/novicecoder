/*
 * DogFactory.cpp
 *
 *  Created on: Mar 6, 2016
 *      Author: bill
 */

#include "DogFactory.h"
#include "Incls.h"
#include "cat.h"

const int count = 2;// 7680500

class Dog {
public:
	Dog() { std::cout << "Dog is born." << std::endl; }
	virtual ~Dog() { std::cout << "Dog destroyed." << std::endl; }
	void bark() { std::cout << "I am just a dog!" << std::endl; }
	void seeCat() { bark(); }
};

class YellowDog : public Dog {
	std::vector<std::string*> _strVect;
	std::string *ptr[count];
public:
	YellowDog() {
		std::cout << "YelloDog created..." << std::endl;
		for(int i = 0; i < count; i++) {
			//_strVect.push_back(new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap....."));
			ptr[i] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
		}
		std::cout << "YelloDog fed..." << std::endl;
	}
	~YellowDog() {
		std::cout << *ptr[0] << std::endl;
		std::cout << *ptr[1] << std::endl;
		for(int i = 0; i < count; i++) {
			delete ptr[i];
		}
		std::cout << "YellowDog destroyed." << std::endl;
	}
	void bark() { std::cout << "I am a yellow dog!" << std::endl; }
};

class DogFactory {
public:
	static Dog* createYellowDog() { return (new YellowDog()); }
//	static std::shared_ptr<Dog> createYellowDog() {
//		return std::shared_ptr<Dog>(new YellowDog());
//	}
};
void scopeTest() {
	Dog *d = new YellowDog();
	d->seeCat();
	delete d;
}

int main_func4() {
//	int count = 500;
//	for(int i = 1; i <= 5; i++) {
//		Dog* pd = DogFactory::createYellowDog();
//		delete pd;
//		std::shared_ptr<Dog> pd = DogFactory::createYellowDog();
//		std::cout << i << " dog..." << (i * count) << std::endl;
//		sleepcp(1000);
//	}
//	Dog *d = new YellowDog();
//	d->seeCat();
//	delete d;
	scopeTest();
	std::string *ptr[10];
	ptr[0] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[1] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[2] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[3] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[4] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[5] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[6] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[7] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[8] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	ptr[9] = new std::string("this is a llot of crap.....this is a llot of crap.....this is a llot of crap.....");
	for(int i = 0; i < 10; i++) {
		delete ptr[i];
	}
	//delete [] ptr;
	std::cout << "All done..." << std::endl;

	return 0;
}
