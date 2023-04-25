all: orderedArray

orderedArray: main.o arrayLisType.o orderedArrayListType.o
	clang++ main.o arrayLisType.o orderedArrayListType.o -o orderedArray

arrayLisType.o: arrayLisType.h

orderedArrayListType.o: orderedArrayListType.h

main.o: main.cpp
	clang++ -c main.cpp

clean: 
	rm -f *.o

pclean:
	rm-f orderedArray
