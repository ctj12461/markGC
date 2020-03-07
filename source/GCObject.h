#ifndef GCOBJECT_H
#define GCOBJECT_H

#include <map>

class IGCObject
{
	friend class GCSystem;
public:
	virtual ~IGCObject() {};
	
	virtual void connect(IGCObject * obj) = 0;
	virtual void disconnect(IGCObject * obj) = 0;
	virtual void mark(bool sign) = 0;
	bool sign() { return GCSign; }
protected:
	bool GCSign;
};

class GCObject : public IGCObject
{
	friend class GCSystem;
public:
	GCObject() {};
	~GCObject() {};
	
	void connect(IGCObject * obj) override;
	void disconnect(IGCObject * obj) override;
	void mark(bool sign) override;
private:
	std::map<IGCObject*, int> Count;
};

#endif
