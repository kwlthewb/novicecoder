/*
 * Inherited.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */
#include "Inherited.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void revStr(char* src) {
    char tmp, *end_ptr, *origin_start, *end_point;
    origin_start = src;
    end_ptr = src + strlen(src) - 1;
    while(end_ptr > src) {
        tmp = *src;
        *src = *end_ptr;
        *end_ptr = tmp;
        src++;
        end_ptr--;
    }
    src = origin_start; // start of the string
    printf("%s\n",src);
    end_ptr = src + strlen(src) - 1;
    end_point = end_ptr;
    while(end_ptr > src) {
        if(std::isalnum(*src)) { // find the pointer at space
            end_ptr = src + 1;
            while(std::isalnum(*end_ptr))
                end_ptr++;
            if(end_ptr - src > 1) {
                char *word_start, *word_end;
                word_start = src;
                word_end = end_ptr - 1;
                while(word_end > word_start) {
                    tmp = *word_start;
                    *word_start = *word_end;
                    *word_end = tmp;
                    word_start++;
                    word_end--;
                }
            }
            src = end_ptr;
            end_ptr = end_point;
        } else {
            src++;
        }

    }
}

int main_func5() {
    std::string str("  this is good   ");
    std::cout << str << "||" << std::endl;
    revStr(const_cast<char*>(str.c_str()));
    std::cout << str << "||" << std::endl;
    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    std::cout << "Start time = " << currentDateTime() << std::endl;;
    Sleep(10000);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - begin;
    std::cout << "End   time = " << currentDateTime() << " || "	<< diff.count() << "s\n";
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//
//void foo(int& aInt)
//{
//    aInt=5;
//}
//
//char* bar()
//{
////    char aa[]="This is my output!";
////    *(aa+5) = 'X';
////    char *bb="This is my output!";
////    //*(bb+5) = 'X'; // error
////    std::cout << strlen(aa) << "," << strlen(bb) << std::endl;
////    std::cout << aa << "," << bb << std::endl;
////    printf("%s |\n",aa);
////    printf("%s |\n",bb);
//    //char *bb="This is my output!";
//    char bb[]="This is my output!";
//
//    return bb;
//}
//
//int main(int argc, char* argv[])
//{
//    int   aa;
//    char* bb = bar();
//    foo(aa);
//    printf("%s %d", bb, aa);
//    return 0;
//}
//
//#include "Inherited.h"
//
//void printStr(char *src) {
//	for(char* it = src; *it; ++it)
//		std::cout << *it;
//	std::cout << "|" << std::endl;
//}
//
//void reverseStr(char *src) {
//	char temp, *end_ptr;
//	if(src == NULL || !(*src))
//		return;
//	std::cout << strlen(src) << std::endl;
//	end_ptr = src + strlen(src) - 1;
//	std::cout << *src << "," << *end_ptr << std::endl;
//	while(end_ptr > src) {
//		temp = *src;
//		*src = *end_ptr;
//		*end_ptr = temp;
//		src++;
//		end_ptr--;
//	}
//}
//
//bool isPalin(std::string srcstr) {
//	// remove special characters first
//	std::string temp("");
//	std::cout << "Input string: " << srcstr << "|" << std::endl;
//	for(std::string::iterator itr = srcstr.begin(); itr != srcstr.end(); ++itr) {
//		if(std::isalnum(*itr))
//			temp += std::tolower(*itr);
//	}
//	std::cout << "Cleaned string: " << temp << "|" << std::endl;
//	char *src = const_cast<char*>(temp.c_str());
//	int i = 0, j;
//	if(src == NULL || src[0] == '\0')
//		return false;
//	j = strlen(src) - 1;
//	while(i < j) {
//		if(src[i] != src[j])
//			return false;
//		i++;
//		j--;
//	}
//	return true;
//}
//

// argument dependent lookup(ADL) only for namespace lookup
namespace A {
	struct X { int i, j; };
	void g(X x) { std::cout << "Struct X: " << x.j << "," << x.i << std::endl; }
	void h(int i) { std::cout << "Calling A::h()\n"; }
	namespace C {
		void h() { std::cout << "Calling A::C::h()\n"; } // it hid A::h()
		void g() { std::cout << "Calling A::C::g()\n"; } // it hid A::h()
		void j() {
			using A::h;
			h(7);
			A::X x;
			g(x);
		}
	}
}
// can't do the below as compiler will err out with ambiguous complaint
//void g(A::X x) {
//	{ std::cout << "Struct X: " << x.j << "," << x.i << std::endl; }
//}

// member functions have higher lookup priority
class B {
public:
	void g(A::X x) { std::cout << "B::g() called\n"; }
};

class C : public B {
public:
	struct Y {};
	//void g(A::X x) { std::cout << "C::g() called\n"; }
	static void h(Y) { std::cout << "Calling C::h()\n"; }
	void j() {
		A::X x;
		g(x);
	}
};


int main_func4() {
	A::X x1;
	x1.i = 99;
	x1.j = -99;
	g(x1);

	C::Y y;
	C::h(y);
	C c;
	c.j();
	//h(y); // error
	A::C::j();
	return 0;
//	std::string s1 ("There are two needles in this haystack with needles.");
//	std::string s2 ("needle");
//
//	size_t found = s1.find(s2);
//	if(found!=std::string::npos){
//		std::cout << "first 'needle' found at: " << found << '\n';
//	}
//	size_t found2 = s1.find(s2,found + 7);
//	if(found2!=std::string::npos){
//		std::cout << "second 'needle' found at: " << found2 << '\n';
//	}
//	size_t found3 = s1.find(s2,found2 + 7);
//	if(found3!=std::string::npos){
//		std::cout << "third 'needle' found at: " << found3 << '\n';
//	}
//
//	int i = 12;
//	double j = 6.6;
//	std::cout << Templates::Square<double>(5.6) << std::endl;
//	std::cout << Templates::Square<double>(2) << std::endl;
//	std::cout << Templates::Square<int>(9) << std::endl;
//	std::cout << Templates::Square(i) << std::endl;
//	std::cout << Templates::Square(j) << std::endl;
//
//	Templates::BoVector<int> bv1;
//	bv1.push(1);
//	bv1.push(3);
//	bv1.push(5);
//	bv1.push(7);
//	bv1.push(9);
//	bv1.print();
//	Templates::BoVector<float> bv2;
//	bv2.push(0.002);
//	bv2.push(0.004);
//	bv2.push(0.006);
//	bv2.push(0.008);
//	bv2.print();
	Inherited::Ninja n;
	Inherited::Monster m;
	Inherited::Enemy *e1 = &n;
	Inherited::Enemy *e2 = &m;
	e1->attack();
	e2->attack();
//	e1->something();
//	e2->something();
	return 0;

//	std::string str("asdj lajsdf aldsj");
//	printStr(const_cast<char*>(str.c_str()));
//
//	std::string str2("1234567890");
//	std::cout << str2 << "|" << std::endl;
//	reverseStr(const_cast<char*>(str2.c_str()));
//	std::cout << str2 << "|" << std::endl;
//
//	std::string str3("Are we not pure? �No sir!� Panama�s moody Noriega brags. �It is garbage!� Irony dooms a man; a prisoner up to new era.");
//	std::cout << isPalin(const_cast<char*>(str3.c_str())) << std::endl;
//
//	return 0;
//
//	Inherited::D_pub d1;
//	d1.f();
//	d1.f_pub();
//	Inherited::D_prot d2;
//	d2.f_pub(); // error unless using B::f_pub is added to D_prot public space
//	d2.f();
//	Inherited::D_priv d3;
//	d3.f();
//
//	Inherited::B* pB = &d1;
//	//pB = &d2;
//
//	InheritedII::yellowdog *py = new InheritedII::yellowdog("Bob");
//	py->bark();
//	InheritedII::dog *pd = py;
//	pd->bark();
//
//	InheritedII::TreeNode *root = new InheritedII::TreeNode();
//	root->right = 0;
//	root->left = 0;
//	InheritedII::EmployeeChart_Parser ep;
//	ep.parse_preorder(root);
//
//	double b1 = 4.0;
//	double b2 = -5.0;
//	if(Templates::aabs(b1) == Templates::aabs(b2))
//		std::cout << b1 << " == " << b2 << std::endl;
//	else
//		std::cout << b1 << " != " << b2 << std::endl;
//
//	Templates::adder<99> aa;
//	Templates::Pow<9,2> aaa;
//	std::cout << aa.doit(5) << std::endl;
//	std::cout << aaa.value << std::endl;
//
//	Templates::SimplePair<int, double> foo = Templates::SimplePair<int, double>{2, 4.56};
//	Templates::SimplePair<InheritedII::dog, InheritedII::yellowdog> foo2
//		= Templates::SimplePair<InheritedII::dog, InheritedII::yellowdog>{
//		InheritedII::dog("Billy"), InheritedII::yellowdog("Bear")};
//
//	std::cout << foo.first << "," << foo.second << std::endl;
//
//	foo2.first.bark();
//	foo2.second.bark();
//
//	Templates::printSomthing<5>("something");
//
//	InheritedII::IOFile f("some file");
//


	return 0;
}
//
//
//
////#include <iostream>
////
////template<typename T> T Square(const T& v) {
////	return v * v;
////}
////
////int main() {
////    int i = 12.2;
////    double j = 4.4;
////    std::cout << Square(12.2) << std::endl;
////    std::cout << Square(4.4) << std::endl;
////    std::cout << Square(i) << std::endl;
////    std::cout << Square(j) << std::endl;
////
////}
