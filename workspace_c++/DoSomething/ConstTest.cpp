/*
 * ConstTest.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: bill
 */

#include "ConstTest.h"

ConstTest::ConstTest() {
	// TODO Auto-generated constructor stub

}

ConstTest::~ConstTest() {
	// TODO Auto-generated destructor stub
}

//class Dog {
//	int age;
//	std::string name;
//public:
//	Dog() { age = 3; name = "dummy"; }
//	void setAge(const int& a) { age = a; std::cout << "Const reference is called." << std::endl; }
//	void setAge(int& a) { age = a; a += 20099; std::cout << "non const reference is called." << std::endl; }
//	void printSomething() { age++; age++; std::cout << age << std::endl; }
//	const std::string& getName() { return name; }
//	void printDogName(int& a) const { std::cout << "const " << name << " age: " << age << std::endl; a++; a++; }
//	void printDogName(int& a) { std::cout << "non-const " << name << " age: " << age << std::endl; a++; a++; }
//};

//class BigArray {
//	std::vector<int> v;
//	int accessCounter;
//	int* v2;
//
//public:
//	BigArray() {
//		accessCounter = 0;
//		v.push_back(11);
//		v.push_back(22);
//		v.push_back(33);
//		v.push_back(44);
//		v.push_back(55);
//		v.push_back(66);
//	}
//	void incAccessAcounter() {
//		accessCounter++;
//		std::cout << accessCounter << std::endl;
//	}
//	int getItem(int index) const {
//		// mutable int accessCounter;
//		//accessCounter++;
//		const_cast<BigArray*>(this)->accessCounter++;
//		std::cout << accessCounter << std::endl;
//		return v[index];
//	}
//	void setV2Item(int index, int x) const {
//		*(v2+index) = x;
//	}
//	//const int* const fun(const int* const& p) const {};
//};

//class dog {
//public:
//	std::string m_name;
//	dog(std::string name = "Bob") { m_name = name; std::cout << name << " is born." << std::endl; }
//	~dog() { std::cout << m_name << " is destroyed." << std::endl; }
//};

//class collar {
//public:
//	collar(std::string color) { std::cout << color << " collar is born." << std::endl; }
//};
//
//class dog {
//	collar m_collar;
//};

//int main() {
////	const int i = 9, j = 9999;
////	const int *p1 = &j;
////	const int *p = new int(129);
////
////	std::cout << *p << std::endl;
////
////	int const *p4 = &j;
////	std::cout << *p4 << std::endl;
////	const int *p5 = &j;
////	std::cout << *p5 << std::endl;
//
////	const int i = 9;
////	std::cout << i << std::endl;
////	const_cast<int&>(i) = 6;
////	std::cout << i << std::endl;
////	Dog d;
////	d.setAge(4);
////	const std::string& n = d.getName();
////	int i = 1;
////	d.setAge(i);
////	std::cout << n << std::endl;
////	std::cout << i << std::endl;
////	d.printDogName(i);
////	std::cout << i << std::endl;
////	const Dog d2;
////	d2.printDogName(i);
////	std::cout << i << std::endl;
////	BigArray ba;
////	std::cout << ba.getItem(3) << std::endl;
//	dog dog1("Henry");
//	dog dog2;
//	dog2 = dog1;
//
//	double i = 123.34;
//	double& j = i;
//	std::cout << i << "," << j << std::endl;
//	i = 2350.230498;
//	std::cout << i << "," << j << std::endl;
//	j = 2383.239999;
//	std::cout << i << "," << j << std::endl;
//
//	dog dog1;
//	return 0;
//}
