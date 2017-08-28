run: main.o student.o list.o
	g++ -o run main.o student.o list.o
student.o: student.cpp student.h
	g++ -c -Wall -pedantic -g -std=c++11 student.cpp
list.o: list.cpp list.h student.h node.h
	g++ -c -Wall -pedantic -g -std=c++11 list.cpp
main.o: main.cpp student.h list.h 
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o student.o list.o run
