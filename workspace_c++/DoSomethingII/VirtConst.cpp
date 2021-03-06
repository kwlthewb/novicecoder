/*
 * VirtConst.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */

#include "VirtConst.h"

namespace ImplicitConver {
class dog {
	std::string m_name;
public:
	dog(std::string name) { m_name = name; } // constructor plus type converter
	//explicit dog(std::string name) { m_name = name; } // constructor plus no implicit converter
	std::string getName() { return m_name; }
	operator std::string() { return m_name; }
	friend std::ostream& operator << (std::ostream& os, const dog& d);
	friend std::istream& operator >> (std::istream& is, dog& d);
};

std::ostream& operator << (std::ostream& os, const dog& d) {
	os << d.m_name;
	return os;
}

std::istream& operator >> (std::istream& is, dog& d) {
	is >> d.m_name;
	return is;
}

class Rational {

public:
	int num;
	int den;
	Rational(int numerator = 0, int denominator = 1) : num(numerator), den(denominator) {
		std::cout << "Rational constructed: " << num << " / " << den << std::endl;
	};
//	const Rational operator*(const Rational& rhs) {
//		return Rational(num*rhs.num, den*rhs.den);
//	}
//	operator int() const {return num/den; }
	// see below
	~Rational() {
		std::cout << "Rational destroyed: " << num << " / " << den << std::endl;
	}
};

}

namespace lrvalue {
// lvalue - an object that occupies some identifiable location in memory
// rvalue - any object that is not a lvalue
}

const ImplicitConver::Rational operator*(const ImplicitConver::Rational& lhs,
		const ImplicitConver::Rational& rhs) {
	return ImplicitConver::Rational(lhs.num*rhs.num, lhs.den*rhs.den);
}

void foo(VirtConst::Dog* d) {
	//VirtConst::Dog* c = new VirtConst::Dog(*d);
	VirtConst::Dog* c = d->clone();
	c->bark();
	delete c;
}

//int square(const int& x) { return x*x; }
// square(40) will error
// workaround for square(40)
int square(const int& x) { return x*x; }
int main_func2() {
//	VirtConst::Yellowdog d;
//	foo(&d);
//	d.bark();
//
//	char c = 'A';
//	int i = c; // integral promotion
//	char* pc = 0; // int -> Null pointer
//	void f(int i);
//	f(c); // c implicitlly converted to int
//	VirtConst::Dog* pd = new VirtConst::Yellowdog();
//
//	std::string dogname = "Bob";
//	ImplicitConver::dog d1 = dogname;
//
//	std::cout << d1 << std::endl;
//	std::cin >> d1;
//	std::cout << d1 << std::endl;
	ImplicitConver::Rational r1 = 23;
	ImplicitConver::Rational r2 = r1 * 2; // compiler can interpret r1 to an int now
	ImplicitConver::Rational r3 = 3 * r1;

	//int i; // i is a lvalue
	//int *p = &i; // i's address is identifiable
	//i = 2; // memory is modified
	//VirtConst::Dog d1; // d1 lvalue of user defined type
	// most variables in C++ code are lvalues

//	int i = 2; // 2 is an rvalue
//	int x = i + 2; // i + 2 is an rvalue
	//int* p = &(i+2); // error
	//i+2 = 4; // error
	//2 = i; //eror


//	int& r = i; // lvalue reference
	//int& r = 5; // error
	const int& m = 5; // constant lvalue reference can be assigned a rvalue
	//int i = 2;
	//square(i); // ok
	//std::cout << square(i) << std::endl;
	std::cout << square(40) << std::endl;
	//square(40); // error
	// workaround;

	// lvalue can be used to create an rvalue
	int i = 1;
	int x = i + 2;
	//int x = i; // i implicilty transformed into rvalue
			   // rvalue cannot be implicitly transformed to lvalue

	// rvalue used to create lvalue
	int v[3]; // operator [] almost always generate lvalues
	*(v+2) = 4;
	// misconception 1: function or operator always yields rvalues

	// misconception 2: lvalues are modifiable
	const int ii = 1;
	// ii is not modifiable

	// misconception 3: rvalues are modifiable
	//i + 3 = 6; // error
}
