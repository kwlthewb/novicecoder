/*
 * InheritII.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: bill
 */

#include "InheritII.h"


// pure virtual public function - inherit interface only
// non-virtual public function - inherit both interface and implementation
// impure virtual public function - inherit interface and default implementation
// protected function - inherit implementation only

namespace InhII {
class Dog {
public:
	virtual ~Dog() { std::cout << "Dog destroyed.\n"; }
	virtual void bark() = 0;
	void run() { std::cout << "I am running.\n"; }
	virtual void eat() { std::cout << "I am eating.\n"; }
protected:
	void sleep() { std::cout << "I am sleeping.\n"; } // provides only implementation not the interface
};

class YellowDog : public Dog {
public:
	virtual ~YellowDog() { std::cout << "YellowDog destroyed.\n"; }
	virtual void bark() { std::cout << "I am a yellow dog.\n"; }
	void isSleep() { sleep(); }
	void run() { std::cout << "YellowDog running..." << std::endl; }
};
}

std::string binaryAdd(const char *p, int size) {
	std::string firstStr("");
	std::string secondStr("");
	bool first = false;
		std::stringstream ss("");
	while(*p != '\0') {
		if(std::isalnum(*p)) {
			ss << *p;
		} else {
			if(!first) {
				firstStr = ss.str();
				first = true;
				ss.str("");
			}
		}
		p++;
	}
	secondStr = ss.str();
	// get the first and second string
	//std::cout << firstStr << "," << firstStr.length() << "," << secondStr << "," << secondStr.length()<< std::endl;
	int count1 = 0, count2 = 0;
	int MAX=0;
	int carry;
	if(firstStr.length() > secondStr.length()) {
		MAX = firstStr.length();
	} else {
		MAX = secondStr.length();
	}
	int firstNum[MAX];
	int secondNum[MAX];
	count1 = MAX - 1;
	count2 = MAX - 1;
	int temp;
	//std::cout << "Ary," << count1 << "," << count2 << std::endl;
	for(std::string::iterator itr = firstStr.end() - 1; itr >= firstStr.begin(); --itr) {
		temp = *itr - '0';
		firstNum[count1] = temp;
		//std::cout << "First," << count1 << "," << temp << std::endl;
		count1--;
	}
	while(count1 >= 0) {
		firstNum[count1] = 0;
		count1--;
	}
	for(std::string::iterator itr = secondStr.end() - 1; itr >= secondStr.begin(); --itr) {
		temp = *itr - '0';
		secondNum[count2] = temp;
		//std::cout << "Second," << count2 << "," << temp << std::endl;
		count2--;
	}
	while(count2 >= 0) {
		secondNum[count2] = 0;
		count2--;
	}

//	std::stringstream ss1(""), ss2("");
//	for(int i = 0; i < MAX; i++) {
//		std::cout << "First, " << firstNum[i] << std::endl;
//	}
//	for(int i = 0; i < MAX; i++) {
//		std::cout << "Second, " << secondNum[i] << std::endl;
//	}

	int result[MAX];
	carry = 0;
	for(int i = MAX - 1; i >= 0; i--)
	{
		if(firstNum[i] + secondNum[i] + carry == 0)
		{
			result[i] = 0;
			carry = 0;
		} else if(firstNum[i] + secondNum[i] + carry == 1)
		{
			result[i] = 1;
			carry = 0;
		} else if(firstNum[i] + secondNum[i] + carry == 2)
		{
			result[i] = 0;
			carry = 1;
		} else if(firstNum[i] + secondNum[i] + carry > 2)
		{
			result[i] = 1;
			carry = 1;
		}
		std::cout << i << "," << firstNum[i] << " + " << secondNum[i] << " = " << result[i] << ",carry," << carry << std::endl;
	}

	std::stringstream ssres("");
	if(carry == 1) {
		ssres << 1;
	}
	for(int j = 0; j < MAX; j++)
	{
		ssres <<result[j];
	}


	std::cout << ssres.str() << std::endl;
	return "";
}

int main_func8() {
//	InhII::YellowDog d;
//	d.bark();
//	d.run();
//	d.isSleep();
	std::string line;
	while(std::getline(std::cin,line)) {
		std::cout << binaryAdd(line.c_str(),line.length()) << std::endl;
	}
}
