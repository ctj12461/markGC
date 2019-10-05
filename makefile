gc : main.o markGC.o GCSystem.o GCObject.o
	g++ -o gc main.o markGC.o GCSystem.o GCObject.o
main.o : main.cpp GCSystem.h
	g++ -c main.cpp
markGC.o : markGC.cpp markGC.h
	g++ -c markGC.cpp
GCSystem.o : GCSystem.cpp GCSystem.h
	g++ -c GCSystem.cpp
GCObject.o : GCObject.cpp GCObject.h
	g++ -c GCObject.cpp

clean :
	rm main.o markGC.o GCSystem.o GCObject.o gc