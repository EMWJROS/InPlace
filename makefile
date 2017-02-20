all: inPlace.exe

inPlace.exe: Matrix.o inPlaceTransposition.o
	g++ -o inPlace.exe -g Matrix.o inPlaceTransposition.o

Matrix.o: Matrix.cpp
	gcc -c Matrix.cpp

inPlaceTransposition.o: inPlaceTransposition.cpp
	gcc -c inPlaceTransposition.cpp

clean:
	rm Matrix.o inPlaceTransposition.o inPlace.exe
	rm *~
