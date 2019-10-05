#include "GCSystem.h"
#include <queue>
using namespace std;

GCSystem::~GCSystem() {
	for(auto i : ObjectsPool){
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
		i.first->mark(sign);
	}
}

void GCSystem::gc() {
	bool nextSign = !GCSign;
	queue<IGCObject*> removeQueue;
	mark(nextSign);
	for(auto i : ObjectsPool) {
		if(i->sign() != nextSign) {
			removeQueue.push(i);
		}
	}
	while(!removeQueue.empty()){
		delete removeQueue.front();
		ObjectsPool.erase(removeQueue.front());
		removeQueue.pop();
	}
}
