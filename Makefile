all: task1

task1: main.o
	clang++ main.o -o task1
main.o: main.cpp
	clang++ -c main.cpp
clean:
	rm -f *.o
pclean:
	rm -f task1 