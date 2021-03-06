/*
 * Casting.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */

#include "Casting.h"

int main_func3() {
	// 1. implicit type conversion
	// 2. explicit type conversion - casting

	// static_cast
//	int i = 9;
//	float f = static_cast<float>(i);
//	VirtConst::Dog d1 = static_cast<VirtConst::Dog>(std::string("Bob"));
//	VirtConst::Dog* pd = static_cast<VirtConst::Dog*>(new VirtConst::Yellowdog()); // down/up cast
//	delete pd;

	// dynamic_cast
	// only work on pointers and references
	// need the 2 types to be polymorphic(have virtual function)
//	VirtConst::Dog* pd = new VirtConst::Yellowdog();
//	VirtConst::Yellowdog* py = dynamic_cast<VirtConst::Yellowdog*>(pd);
//	delete pd;
	//delete py;

	// const_cast
	// only works on pointer and references
	// only works on same type
	// cast away constness
	const std::string* str = new std::string("Hello world");
	std::cout << *str << std::endl;
	std::string* modifiable = const_cast<std::string*>(str);
	modifiable->append("asdflj");
	std::cout << *str << std::endl;
	std::cout << *modifiable << std::endl;

	// reinterpret_cast
	// most powerful, re-interpret the bits of the object pointed to
	// the ultimate cast that can cast one pointer to any other type of pointer
	// use for low level casting
	long p = 51110980;
	VirtConst::Dog* dd = reinterpret_cast<VirtConst::Dog*>(p);


	Casting::dog *pd = new Casting::yellowdog();
	Casting::yellowdog *py = dynamic_cast<Casting::yellowdog*>(pd); // incorrect but doesn't cause error
	py->bark(); // no error because compiler interpreted bark to be a static function
	std::cout << "py = " << py << std::endl;
	std::cout << "pd = " << pd << std::endl;

}
