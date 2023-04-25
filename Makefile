all: task2

task2: main.o
	clang++ main.o -o task2
main.o: main.cpp
	clang++ -c main.cpp
clean:
	rm -f *.o
pclean:
	rm -f task2 