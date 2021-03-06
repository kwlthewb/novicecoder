/*
 * Timer.h
 *
 *  Created on: Feb 14, 2016
 *      Author: bill
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Timer {
public:
	Timer();
	Timer(int i, double j);
	virtual ~Timer();
	void doSomething();
private:
	int _i1;
	int _i2;
	int _i3;
	double _d1;
	double _d2;
	double _d3;
};

#endif /* TIMER_H_ */
