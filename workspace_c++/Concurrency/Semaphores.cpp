/*
 * Semaphores.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: bill
 */

#include "Semaphores.h"

sem_t s;

void *myfunc1(void *ptr) {
	char *msg = (char *) ptr;
	int count = 0;
	while(count < 100) {
		printf("%d %s sleeping...\n",count,msg);
		sleepcp(2000);
		count++;
	}
}

void *myfunc2(void *ptr) {
	char *msg = (char *) ptr;
	int count = 0;
	while(count < 100) {
		printf("%d %s sleeping...\n",count,msg);
		sleepcp(2000);
		count++;
	}
	pthread_exit(0);
}

void func1(int tid, int ss) {
	int count = 0;
//	std::ofstream ofs;
//	ofs.open ("test.txt", std::ofstream::out | std::ofstream::app);
	//std::cout << "Thread started: " << tid << " " << ss << " ||\n";
	while(count < 5) {
		sem_wait(&s);
		std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
		std::cout << "Start time = " << currentDateTime() << " Started thread ID: " << tid << " " << ss << " ||\n";
		//ofs << "Beauty is only skin-deep.\n";
		//sleepcp(ss);
		Sleep(ss);
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - begin;
		std::cout << "End   time = " << currentDateTime() << " Ended   thread ID: " << tid << " " << ss << " || "
				<< diff.count() << "s\n";
		sem_post(&s);
		count++;
	}
	//ofs.close();
}

void workerFunc(const char* msg, size_t delay) {
	boost::posix_time::seconds workTime(delay);
	int count = 0;
	while(count < 20) {
		std::cout << msg << std::endl;
		boost::this_thread::sleep(workTime);
		count++;
	}
	std::cout << msg << " done.\n";
}

int main() {
	setvbuf (stdout, NULL, _IONBF, BUFSIZ);
	sem_init(&s, 0, 5); // max 2 thread can work
//	pthread_t t1,t2;
//	char *msg1 = "Thread 1";
//	char *msg2 = "Thread 2";
//	pthread_create(&t1, NULL, myfunc1,(void *)msg1);
//	pthread_create(&t2, NULL, myfunc2,(void *)msg2);
//
//	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);
#ifdef LINUX
	std::cout << "LINUX defined" << std::endl;
#endif
#ifdef WINDOWS
	std::cout << "WINDOWS defined" << std::endl;
#endif
	int n = 20;
	std::thread myThreads[n];
	std::ostringstream ss;
	for(int i = 0; i < n; i++) {
		ss.str("");
		ss << "Thread " << i << ":";
		std::string msg = ss.str();
		myThreads[i] = std::thread(func1,i,6000);
		sleepcp(200);
	}
	for(int i = 0; i < n; i++) {
		myThreads[i].join();
	}
	//t1.detach(); // break thread from main thread, let it run on its own as daemon proces

//	boost::thread t1(workerFunc,"Thread 1", 1);
//	boost::thread t2(workerFunc,"Thread 2", 2);
//	boost::thread t3(workerFunc,"Thread 3", 3);
//	t1.join();
//	t2.join();
//	t3.join();
	return 0;
}
