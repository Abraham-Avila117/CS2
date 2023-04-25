all: SSX

SSX: main.o
	clang++ main.o -o SSX

main.o: main.cpp
	clang++ -c main.cpp

clean: 
	rm -f *.o

pclean:
	rm-f SSX
