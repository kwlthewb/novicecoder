/*
 * InheritII.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: bill
 */

#include "InheritII.h"

namespace InhII {
class Dog {
public:
	virtual void bark() = 0;
};

class YellowDog : public Dog {
public:
	virtual void bark() { std::cout << "I am a yellow dog.\n"; }
};
}

int main() {
	InhII::YellowDog d;
	d.bark();
}
