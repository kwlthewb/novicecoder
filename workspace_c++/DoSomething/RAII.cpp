/*
 * RAII.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#include "RAII.h"
#include "Incls.h"

RAII::RAII() {
	// TODO Auto-generated constructor stub

}

RAII::~RAII() {
	// TODO Auto-generated destructor stub
}

//Mutex_t mu = MUTEX_INITIALIZER;
//
//void functionA() {
//	Mutex_lock(&mu);
//	std::cout << "Do something..." << std::endl;
//	Mutex_unlock(&mu);
//}
//
//class Lock {
//private:
//	Mutex_t* m_pm;
//public:
//	explicit Lock(Mutex_t *pm) { Mutex_lock(pm); m_pm = pm; }
//	~Lock() { Mutex_unlock(m_pm); }
//};
//
//void functionB(){
//	Lock mylock(&mu);
//}
