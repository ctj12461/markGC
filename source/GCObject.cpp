#include "GCObject.h"
using namespace std;

void GCObject::connect(IGCObject * obj) {
	++Count[obj];
}

void GCObject::disconnect(IGCObject * obj) {
	--Count[obj];
}

void GCObject::mark(bool sign) {
	GCSign = sign;
}
