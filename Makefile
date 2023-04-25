all: bst

bst: main.o 
	clang++ main.o -o bst

main.o: main.cpp
	clang++ -c main.cpp

clean: 
	rm -f *.o

pclean:
	rm -f bst