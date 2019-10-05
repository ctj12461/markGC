#ifndef MARKGC_H
#define MARKGC_H

#include "GCSystem.h"
#include "GCObject.h"
#include <utility>

template <typename T>
IGCObject * gcnew(GCSystem& sys) {
	IGCObject * p = new T;
	sys.ObjectsPool.insert(p);
	return p;
}

#endif