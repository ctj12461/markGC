#include "GCSystem.h"
#include <queue>
using namespace std;

GCSystem::~GCSystem() {
	for (auto i : ObjectsPool){
		delete i;
	}
	ObjectsPool.clear();
}

void GCSystem::connect(IGCObject * obj) {
	ObjectsPool.insert(obj);
	++Count[obj];
}

void GCSystem::disconnect(IGCObject * obj) {
	--Count[obj];
}

void GCSystem::mark(bool sign) {
	GCSign = sign;
	queue<IGCObject*> q;
	for (auto it = Count.begin(), ed = Count.end(); it != ed;) {
		if(it->second <= 0) {
			Count.erase(it++);
		} else if (it->first->GCSign != sign) {
			q.push(it->first);
			++it;
		}
	}
	while (!q.empty()) {
		GCObject *now = static_cast<GCObject*>(q.front()); q.pop();
		now->mark(sign);
		for (auto it = now->Count.begin(), ed = now->Count.end(); it != ed;) {
			if(it->second <= 0) {
				now->Count.erase(it++);
			} else if (it->first->GCSign != sign) {
				q.push(it->first);
				++it;
			}
		}
	}
}

void GCSystem::gc() {
	bool nextSign = !GCSign;
	mark(nextSign);
	for (auto it = ObjectsPool.begin(), ed = ObjectsPool.end(); it != ed;) {
		if((*it)->sign() != nextSign) {
			delete *it;
			ObjectsPool.erase(it++);
		} else {
			++it;
		}
	}
}
