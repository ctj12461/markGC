Test2 : Test2.o markGC.o GCSystem.o GCObject.o
	g++ -o Test2 Test2.o markGC.o GCSystem.o GCObject.o
Test2.o : Test2.cpp ../../Source/GCSystem.h
	g++ -c Test2.cpp
markGC.o : ../../Source/markGC.cpp ../../Source/markGC.h
	g++ -c ../../Source/markGC.cpp
GCSystem.o : ../../Source/GCSystem.cpp ../../Source/GCSystem.h
	g++ -c ../../Source/GCSystem.cpp
GCObject.o : ../../Source/GCObject.cpp ../../Source/GCObject.h
	g++ -c ../../Source/GCObject.cpp

run : Test2
	./Test2

clean :
	rm Test2.o markGC.o GCSystem.o GCObject.o Test2