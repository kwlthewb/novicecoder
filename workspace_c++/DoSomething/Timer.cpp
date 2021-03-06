/*
 * Timer.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: bill
 */

#include "Timer.h"

Timer::Timer() {
	// TODO Auto-generated constructor stub
	_i1 = 100;
	_i2 = 200;
	_i3 = 300;
	_d1 = 111.11;
	_d2 = -222.22;
	_d3 = 333.33;
}

Timer::Timer(int i, double j) : Timer() {
	// TODO Auto-generated constructor stub
	_i1 = i;
	_d1 = j;
}


Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

void Timer::doSomething() {
	std::cout << _i1 << "," << _i2 << "," << _i3 << "," << _d1 << "," << _d2 << "," << _d3 << std::endl;
}

//int main(int argc, char** args) {
//	std::cout << "Hello world!!" << std::endl;
//	int something;
//	std::cin >> something;
//	std::cout << something << std::endl;
//	Timer t[4];
//	t[0].doSomething();
//	t[1].doSomething();
//	t[2].doSomething();
//	t[3].doSomething();
//
//}

#include <iostream>

class A
{
public:
    A(int n = 0)
        : m_n(n)
    {
        std::cout << 'd';
    }

    A(const A& a)
        : m_n(a.m_n)
    {
        std::cout << 'c';
    }
    void doSomething() const {
    	std::cout << "DoSomething.." << m_n << std::endl;
    }
    void setInt(int n) {
    	m_n = n;
    }

private:
    int m_n;
};

void f(const A &a1, const A &a2 = A())
{
}

int main_func2()
{
    A a(2), b; // dd
    std::cout << ';' << std::endl;
    a.doSomething();
    const A c(a); // c
    std::cout << ';' << std::endl;
    c.doSomething();
    const A &d = a; // nothing
    std::cout << ';' << std::endl;
    d.doSomething();
    a.setInt(9999999);
    std::cout << "Set int to 999" << std::endl;
    a.doSomething();
    c.doSomething();
    d.doSomething();
    const A e = b; //c
    std::cout << ';' << std::endl;
    //b = d;
    std::cout << ';' << std::endl;
    A *p = new A(c), *q = &a; //c
    std::cout << ';' << std::endl;
    static_cast<void>(q);
    std::cout << ';' << std::endl;
    delete p;
    std::cout << ';' << std::endl;
    f(3,3); // dd
    std::cout << ';' << std::endl;
    std::cout << std::endl;

    return 0;
}
