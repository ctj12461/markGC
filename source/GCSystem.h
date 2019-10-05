#ifndef GCSYSTEM_H
#define GCSYSTEM_H

#include "GCObject.h"
#include <set>

class GCSystem : public IGCObject
{
	template <typename T> 
	friend IGCObject * gcnew(GCSystem& sys);
public:
	GCSystem() {};
	~GCSystem();

	void connect(IGCObject * obj) override;
	void disconnect(IGCObject * obj) override;
	void mark(bool sign) override;
	void gc();
private:
	std::map<IGCObject*, int> Count;
	std::set<IGCObject*> ObjectsPool;
};

#endif