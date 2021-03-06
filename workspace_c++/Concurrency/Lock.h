/*
 * Lock.h
 *
 *  Created on: Mar 27, 2016
 *      Author: bill
 */

#ifndef LOCK_H_
#define LOCK_H_
#include <iostream>
#include <mutex>

class Lock {
private:
	std::mutex *m_pm;
public:
	explicit Lock(std::mutex *m) : m_pm(m) {
		//std::cout << "Lock acquired...\n" << std::flush;
		m->lock();
		m_pm = m;
	};
	~Lock() {
		//std::cout << "Lock destroyed...\n" << std::flush;
		m_pm->unlock();
	};
};

#endif /* LOCK_H_ */
