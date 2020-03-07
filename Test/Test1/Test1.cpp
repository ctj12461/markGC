/*
This is a small test to show the basic operations and features of the GC.
*/

#include <iostream>
#include "../../Source/markGC.h"
using namespace std;

GCSystem sys;

class TestA : public GCObject
{
public:
	TestA() {
		UUID=TestA::getUUID();
		cout << "Constructor : TestA " << UUID << endl;
	}
	~TestA() {
		cout << "Destructor : TestA " << UUID << endl;
	}
	int UUID;
private:
	static int IDAlloc;
	static int getUUID() {
		return IDAlloc++;
	}
};

class TestB : public GCObject
{
public:
	TestB() {
		UUID=TestB::getUUID();
		cout << "Constructor : TestB " << UUID << endl;
	}
	~TestB() {
		cout << "Destructor : TestB " << UUID << endl;
	}
	int UUID;
private:
	static int IDAlloc;
	static int getUUID() {
		return IDAlloc++;
	}
};

int TestA::IDAlloc = 1;
int TestB::IDAlloc = 1;

int main() {
	IGCObject * p1, * p2, * p3, * p4;
	p1 = gcnew<TestA>(sys);
	p2 = gcnew<TestA>(sys);
	p3 = gcnew<TestB>(sys);
	p4 = gcnew<TestB>(sys);
	cout << "Get 4 Objects" << endl;
	sys.connect(p1); 
	p1->connect(p2);
	p2->connect(p3);
	p3->connect(p4);
	p4->connect(p1);
	cout << "Disconnect p1" << endl;
	sys.disconnect(p1);
	sys.gc();

	return 0;
}
