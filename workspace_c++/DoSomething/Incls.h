/*
 * Incls.h
 *
 *  Created on: Mar 7, 2016
 *      Author: bill
 */

#ifndef INCLS_H_
#define INCLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <exception>
#include <time.h>
#include <memory>
#include <pthread.h>

static void sleepcp(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}


#endif /* INCLS_H_ */
