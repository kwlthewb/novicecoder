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
#include <fstream>
#include <vector>
#include <exception>
#include <time.h>
#include <memory>
#include <pthread.h>
#include <string.h>
#include <cctype>
#include <functional>
#include <string>
#include <semaphore.h>
#include <thread>
#include <chrono>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <time.h>
#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

static const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

static void sleepcp(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;

    while (clock() < time_end)
    {
    }
}

#endif /* INCLS_H_ */
