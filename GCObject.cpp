#include "GCObject.h"
#include <queue>
using namespace std;

void GCObject::connect(IGCObject * obj) {
	++Count[obj];
}

void GCObject::disconnect(IGCObject * obj) {
	--Count[obj];
}

void GCObject::mark(bool sign) {
	queue<pair<IGCObject*, int> > removeQueue;
	GCSign = sign;
	for(auto i : Count) {
		if(i.second <= 0) {
			removeQueue.push(i);
		}
	}
	while(!removeQueue.empty()) {
		Count.erase(removeQueue.front().first);
		removeQueue.pop();
	}
	for(auto i : Count) {
		if(i.first->sign() != GCSign) {
			i.first->mark(sign);
		}
	}
}
