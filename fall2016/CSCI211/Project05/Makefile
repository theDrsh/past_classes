run: main.o student.o dlist.o
	g++ -o run main.o student.o dlist.o
student.o: student.cpp student.h
	g++ -c -Wall -pedantic -g -std=c++11 student.cpp
dlist.o: dlist.cpp dlist.h student.h node.h
	g++ -c -Wall -pedantic -g -std=c++11 dlist.cpp
main.o: main.cpp student.h dlist.h priority_queue.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o student.o dlist.o run
