#include <iostream>
#include <ctime>
#include "../../Source/markGC.h"

using namespace std;

class TestClass : public GCObject
{
public:
    TestClass() { UUID=TestClass::getUUID(); }
    ~TestClass() {}
    static int getUUIDValue() { return IDAlloc; }
    int UUID;
private:
    static int IDAlloc;
    static int getUUID() { return ++IDAlloc; }
};

int TestClass::IDAlloc = 0;

GCSystem sys;
const int maxtime = 10000;

int main() {
    cout << "#1" << endl;
    IGCObject * root = gcnew<TestClass>(sys);
    sys.connect(root);
    clock_t start = clock();
    for (int i = 0; i < maxtime; ++i) {
        IGCObject * tmp = gcnew<TestClass>(sys);
        root->connect(tmp);
    }
    cout << "Object count : " << TestClass::getUUIDValue() << endl;
    cout << "Disconnect root" << endl;
    sys.disconnect(root);
    sys.gc();
    cout << "Time : " << start - clock() << "ms" << endl;

    cout << "#2" << endl;
    start = clock();
    for (int i = 0; i < maxtime; ++i) {
        TestClass *tmp = new TestClass;
        delete tmp;
    }
    cout << "Time : " << start - clock() << "ms" << endl;
    cout << "Test End" << endl;
    return 0;
}