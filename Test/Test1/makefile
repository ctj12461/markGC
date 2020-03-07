Test1 : Test1.o markGC.o GCSystem.o GCObject.o
	g++ -o Test1 Test1.o markGC.o GCSystem.o GCObject.o
Test1.o : Test1.cpp ../../Source/GCSystem.h
	g++ -c Test1.cpp
markGC.o : ../../Source/markGC.cpp ../../Source/markGC.h
	g++ -c ../../Source/markGC.cpp
GCSystem.o : ../../Source/GCSystem.cpp ../../Source/GCSystem.h
	g++ -c ../../Source/GCSystem.cpp
GCObject.o : ../../Source/GCObject.cpp ../../Source/GCObject.h
	g++ -c ../../Source/GCObject.cpp

clean :
	rm Test1.o markGC.o GCSystem.o GCObject.o Test1