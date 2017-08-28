run: main.o  bst.o student.o
	g++ -o run main.o  bst.o student.o
bst.o: bst.cpp bst.h  tnode.h
	g++ -c -Wall -pedantic -g -std=c++11 bst.cpp
student.o: student.cpp student.h 
	g++ -c -Wall -pedantic -g -std=c++11 student.cpp
main.o: main.cpp  bst.h student.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o bst.o student.o run
