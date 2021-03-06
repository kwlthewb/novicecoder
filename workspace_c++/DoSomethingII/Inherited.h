/*
 * Inherited.h
 *
 *  Created on: Mar 8, 2016
 *      Author: bill
 */

#ifndef INHERITED_H_
#define INHERITED_H_
#include "Incls.h"

namespace Inherited {

class Inherited {
public:
	Inherited();
	virtual ~Inherited();
};

class B {
public:
	void f_pub() { std::cout << "f_pub is called" << std::endl; }
protected:
	void f_prot() { std::cout << "f_prot is called" << std::endl; }
private:
	void f_priv() { std::cout << "f_priv is called" << std::endl; }

};

class D_priv : private B {
public:
	void f(){
		f_pub(); // ok, D_priv's private function
		f_prot(); // ok, D_priv's private function
		//f_priv(); // error
	}
};
class D_prot : protected B {
public:
	using B::f_pub;
	void f(){
		f_pub(); // ok, D_pub's protected function
		f_prot(); // ok, D_pub's protected function
		//f_priv(); // error
	}

};
class D_pub : public B {
public:
	void f(){
		f_pub(); // ok, D_pub's public function
		f_prot(); // ok, D_pub's protected function
		//f_priv(); // error
	}
};

/*
 * Access Control:
 * 1. None of the derived classes can access anything that is private in B.
 * 2. D_pub inherits public members of B as public and the protected members of B as protected
 * 3. D_priv inherits the public and protected members of B as private
 * 4. D_prot inherits the public and protected members of B as protected
 * Casting:
 * 1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B.
 * 2. D_priv's members and friends can cast a D_priv* to B*
 * 3. D_prot's members, friends, and children can cast a D_prot* to B*
 */

/*
 * public inheritance: is-a relation, eg, D_pub is-a kind of B
 * private inheritance: similar to has-a relation
 */

class ring {
public:
	void tinkle() { std::cout << "Ring tinkle...\n"; }
};

/* composition */
class dog {
	ring m_ring;
public:
	void tinkle() { m_ring.tinkle(); } // call forwarding
};

/* private inheritance */
class dog2 : private ring {
public:
	using ring::tinkle;
};
/* composition preferred over private inheritance */

class bird {
};

class flayablebird : public bird {
public:
	void fly();
};

class penguin : public bird {};

class InputFile {
	void open();
public:
	void read();
};

class OutputFile {
public:
	void open() { std::cout << "OutputFile open() is called.\n"; };
	void write();
};

class IOFile: public InputFile, public OutputFile {
};

class Enemy {
public:
	void attack() {
		std::cout << "Enemy class attack" << std::endl;
	};
	//virtual void attack()=0;
	void something() {
		std::cout << "something from Enemy class" << std::endl;
	}
};

class Ninja : public Enemy {
public:
	void attack() {
		std::cout << "Ninja attack!" << std::endl;
	}
	void something() {
		std::cout << "something from Ninja class" << std::endl;
	}
};

class Monster : public Enemy {
public:
	void attack() {
		std::cout << "Monster attack!" << std::endl;
	}
};

class A1 {
public:
	virtual void doSomething() {
		std::cout << "A1 does something..." << std::endl;
	}
};

class A2 {
public:
	void doSomething() {
		std::cout << "A2 does something..." << std::endl;
	}
};

class C : public A1, public A2 {

};

} /* namespace Inherited */


namespace InheritedII {
class dog{
	std::string m_name;
public:
	dog() { std::cout << "A dog is born.\n"; };
	dog(std::string name) : m_name(name) {
		std::cout << m_name << " dog is born.\n";
	};
	virtual void bark(std::string msg = "a dog") { std::cout << msg << " " << m_name << " is a dog.\n"; }
};

class yellowdog : public dog {
	std::string m_name;
public:
	yellowdog(std::string name) : m_name(name) {
		std::cout << m_name << " yellowdog is born.\n";
	};
	virtual void bark(std::string msg = "a yellowdog") { std::cout << msg << " " << m_name << " is a yellowdog.\n"; }
};

struct TreeNode {TreeNode *left, *right;};

class Generic_Parser {
   public:
   void parse_preorder(TreeNode* node) {
      if (node) {
         process_node(node);
         parse_preorder(node->left);
         parse_preorder(node->right);
      }
   }
   private:
   virtual void process_node(TreeNode* node) { }
};

class EmployeeChart_Parser : public Generic_Parser {
   private:
   void process_node(TreeNode* node) {
       std::cout << "Customized process_node() for EmployeeChart.\n";
   }
};
//              File
//              /   \
//      InputFile   OutputFile
//              \   /
//              IOFile
class File {
public:
	File(std::string fname) : name(fname) {
		std::cout << "File is born " << name << std::endl;
	};
	std::string name;
	void open();
};
                                 // still problem because name and open()are in herited
                                 // by IOFile
//
//class InputFile : public File {
//
//};
//
//class OutputFile : public File {
//
//};
// solution, but with virtual compiler will not have default constructor in File
class InputFile : virtual public File {
	std::string name;
public:
	InputFile(std::string fname) : name(fname), File(fname) {
		std::cout << "InputFile is born " << name << std::endl;
	};
};

class OutputFile : virtual public File {
	std::string name;
public:
	OutputFile(std::string fname) : name(fname), File(fname) {
		std::cout << "OutputFile is born " << name << std::endl;
	};
};

class IOFile : public InputFile, public OutputFile {
public:

	IOFile(std::string fname) : OutputFile(fname), InputFile(fname), File(fname) {

	}
};

}

namespace Templates {
template<typename T> T aabs(T myNum) {
	if(myNum < 0) {
		return -myNum;
	}
	return myNum;
}

template<int ToAdd> class adder {
public:
	int doit(int x);
};

template<int ToAdd> int adder<ToAdd>::doit(int x) {
	return ToAdd + x;
}

template<int B, int E> class Pow{
public:
	static const int value = B * Pow<B, E - 1>::value;
};
template<int B> class Pow<B, 0>{
public:
	static const int value = 1;
};

template<typename Tfirst, typename Tsecond> struct SimplePair{
	Tfirst first;
	Tsecond second;
	SimplePair(Tfirst f, Tsecond s) : first(f), second(s) {};
};

template<size_t NumCopies> void printSomthing(const std::string& str) {
	for(size_t i = 0; i < NumCopies; i++ ) {
		std::cout << i << ": " << str << std::endl;
	}
}

template<size_t n> struct fact;
template<> struct fact<0> {
	const static auto value = 1;
};

template<typename T> T Max(std::vector<T>& v) {
	T max = v[0];
	for(typename std::vector<T>::iterator itr = v.begin(); itr != v.end(); itr++) {
		if(*itr > max)
			max = *itr;
	}
	return max;
}

// code bloat - different Square function with different space in final function
template<typename T> T Square(const T& v) {
	return v * v;
}

template<typename T> class BoVector {
	T arr[1000];
	int size;
public:
	BoVector() : size(0) {};
	void push(T x) { arr[size] = x; size++; }
	void print() const {
		for(int i = 0; i < size; i++) {
			std::cout << arr[i] << std::endl;
		}
	}
};
}

#endif /* INHERITED_H_ */
