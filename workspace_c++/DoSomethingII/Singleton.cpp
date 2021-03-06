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
	//Singleton s;
	dog* pd = Singleton::getDog();
	pd->bark();
//	cat* pc = Singleton::getCat();
//	pc->meow();
	dog* pd2 = Singleton::getDog();
	pd2->bark();
//	cat* pc2 = Singleton::getCat();
//	pc2->meow();
	dog* pd3 = Singleton::getDog();
	pd3->bark();
//	cat* pc3 = Singleton::getCat();
//	pc3->meow();

}

// small passive objects that carry public data and have no or few basic member functions
// data container
struct Person_t {
	std::string name; // public
	unsigned age;
private:
	int height;
};

// Bigger active objects that carry private data, interfaced through public member functions
// Complex data structure
//class Person {
//	std::string name_; // private
//	unsigned age_; // m_age, _age(official name convention in python for private and class member
//	// _C__ internal member
//public:
//	int height;
//	unsigned age() const { return age_; } // getter / access almost always const function
//	void set_age(unsigned a) { age_ = a; } // setter / mutator
//};
class Person {
	std::string* pName_;
public:
	Person(std::string name) {
		pName_ = new std::string(name);
		std::cout << "New Person: " << *pName_ << std::endl;
	}
	// Solution 1: Define copy constructor and copy assignment operator for deep copying
	Person(const Person& rhs) {
		pName_ = new std::string(*(rhs.pName()));
	}
	Person& operator=(const Person& rhs) {
		if(this == &rhs)
			return *this;
		pName_ = new std::string(*(rhs.pName()));
		return *this;
	}
	Person* cloneByPtr() {
		std::cout << "CloningByPtr..." << std::endl;
		return new Person(*pName_);
	}
	Person& cloneByRef() {
		std::cout << "CloningByRef..." << std::endl;
		Person p(*pName_);
		return p;
	}
	Person clone() {
		std::cout << "Cloning..." << std::endl;
		Person p(*pName_);
		return p;
	}
	~Person() { delete pName_; }
	void printName() { std::cout << *pName_ << std::endl; }
	std::string* pName() const { return pName_; }
	void setName(std::string name) { pName_ = new std::string(name); }
private:
	// Solution 2: Delete copy constructor and copy assignment operator for deep copying
	//             define clone function
//	Person(const Person& rhs);
//	Person& operator=(const Person& rhs);
};

int main_func() {
//	Singleton::getCat()->meow();
//	scope();
//	Person_t PT;
//	PT.age = 34;
//	std::cout << PT.age << std::endl;
//	Person P;
//	P.set_age(55);
//	std::cout << P.age() << std::endl;

	std::vector<Person> persons;
	// step 1. "George" is constructed
	// step 2. A copy of "George" is saved (shallow copy)
	// step 3. "George" is destroyed
	// the problem: *pName_ from the original object and the copy are pointing to the same thing
	// when the original is destroyed, the copied object's pName_ no longer points to valid object
	persons.push_back(Person("George"));
	persons.push_back(Person("Bill"));
	persons.push_back(Person("Bob"));
	persons.push_back(Person("Eric"));
	persons.back().printName();

//	Person p1("Amanda");
//	p1.printName();
//	Person p2("Michelle");
//	p2.printName();
//	p2 = p1;
//	p1.printName();
//	p2.printName();

//	std::vector<Person*> persons;
//	persons.push_back(new Person("George"));
//	persons.push_back(new Person("Bill"));
//	persons.push_back(new Person("Bob"));
//	persons.push_back(new Person("Eric"));
//	persons.back()->printName();

	Person p1("Amanda");
	Person* p2 = p1.cloneByPtr();
	Person& p3 = p1.cloneByRef();
	Person p4("Mishie");
	p1 = p4;
	p1.printName();
	//Person p4 = p1.clone();
	//p2->setName("Billy");
	p2->printName();
	//p3.setName("Bear");
	p3.printName();
	//p2->setName("Billy2");
	p2->printName();
	//p3.setName("Bear2");
	p3.printName();
	//p4.printName();
	std::cout << "Done" << std::endl;

}
