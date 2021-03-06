/*
 * NotAllowed.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: bill
 */

#include "NotAllowed.h"

NotAllowed::NotAllowed() {
	// TODO Auto-generated constructor stub

}

NotAllowed::~NotAllowed() {
	// TODO Auto-generated destructor stub
}

class OpenFile {
	std::string fname;
public:
	OpenFile(std::string filename) { fname = filename; std::cout << filename << std::endl; }
	void destroyMe() { delete this; }
	//g(OpenFile& f) { OpenFile f2(f); }
private:
	// private destructor is utilized for reference counting pointers
	// cannot be destroyed by anyone else but itself or friend
	// private destructor can only be stored on heap and not stack
	~OpenFile() { std::cout << "OpenFile is destroyed." << std::endl; }
};

//int main() {
//	// f is on the stack, when it is unwind from stack destructor will be called again
//	//OpenFile f("/some path/some file/some file2");
//	//f.destroyMe();
//	OpenFile *f = new OpenFile("/some path/some file/some file2");
//	f->destroyMe();
//
//	pthread_attr_t attr;
//	size_t stacksize;
//
//	pthread_attr_init(&attr);
//	pthread_attr_getstacksize(&attr, &stacksize);
//
//	printf("%u\n", stacksize);
//
//	return 0;
//}
