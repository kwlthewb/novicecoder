/*
 * pointers.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: bill
 */

#include "pointers.h"

struct A {
	A() : int_ptr_(new int) {}
	~A() {
		std::cout << "Delete pointer" << std::endl;
		//delete int_ptr_;
	}
private:
	//int *int_ptr_;
	boost::scoped_ptr<int> int_ptr_;
};

namespace ppp {
class Dog{
	std::string m_name;
public:
	Dog(std::string n) : m_name(n) {
		std::cout << "Dog is created: " << m_name << std::endl;
	}
	Dog() {
		m_name = "";
		std::cout << "Dog is created: nameless\n";
	}
	~Dog() {
		std::cout << "Dog is destroyed: " << m_name << std::endl;
	}
	void bark() {
		std::cout << "Dog " << m_name << " rules..." << std::endl;
	}
};

}

void foo() {
	ppp::Dog *p = new ppp::Dog("Gunner");
	delete p;
	//p->bark(); // p is dangling pointer -> undefined behavior
}

void foo2() {
	// 1. Dog("dick") is created, then p is created, not exception safe
	std::shared_ptr<ppp::Dog> p(new ppp::Dog("dick"));// count = 1

	{
		std::shared_ptr<ppp::Dog> p2 = p; // count = 2
		std::shared_ptr<ppp::Dog> p3 = p; // count = 2
		std::shared_ptr<ppp::Dog> p4 = p; // count = 2
		p2->bark();
		p3->bark();
		p4->bark();
		(*p4).bark();
		std::cout << p.use_count() << std::endl;
		std::cout << p2.use_count() << std::endl;
		std::cout << p3.use_count() << std::endl;
		std::cout << p4.use_count() << std::endl;
	}  // count = 1
	p->bark();
	std::cout << p.use_count() << std::endl;
}// count = 0

// unique pointers: exclusive ownership, light weight smart pointer
void uniqueFoo() {
	std::unique_ptr<ppp::Dog> p(new ppp::Dog("UniqueGunner"));
	p->bark();
//	ppp::Dog *p2 = p.release();
//	p2->bark();
//	if(!p) {
//		std::cout << "p is empty" << std::endl;
//	}
}

int main_func() {
	uniqueFoo();
	//foo();
	//foo2();
	// An object should be assigned to a smart pointer as soon as it is created.
	// Raw pointer should not be used.
//	ppp::Dog* d = new ppp::Dog("Tank"); // bad idea
//	std::shared_ptr<ppp::Dog> p(d); // p.user_count() = 1
//	std::shared_ptr<ppp::Dog> p2(d); // p2.user_count() = 1
	// short-cut to the problem above
	// faster and safer, exception safe
	//std::shared_ptr<ppp::Dog> p3 = std::make_shared<ppp::Dog>("Tank2");

	std::shared_ptr<ppp::Dog> p1 = std::make_shared<ppp::Dog>("Gunner"); // using default deleter
	std::shared_ptr<ppp::Dog> p2 = std::make_shared<ppp::Dog>("Tank");
	std::shared_ptr<ppp::Dog> p3 = std::shared_ptr<ppp::Dog>(new ppp::Dog("Tank2"),
			[](ppp::Dog *p) { p->bark();
							  delete p;
							});
	//p1 = p2; // Gunner is deleted
	//p1 = nullptr; // Gunner is deleted
	//p1.reset(); // Gunner is deleted
	//Sleep(6000);
	return 0;
	// static_pointer_cast
	// dynamic_pointer_cast
	// const_pointer_cast

	int* int_ptr2 = new int;
	int* int_ptr;
	int i = 456;
	int_ptr = &i;
	*int_ptr2 = 2221212;
	std::cout << *int_ptr2 << std::endl;
	i = 999;
	*int_ptr2 = 99999;
	std::cout << *int_ptr2 << std::endl;
	delete int_ptr2;
	return 0;
}
