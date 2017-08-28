vector: student.o main.o Vector.o
	g++ -o vector -Wall -pedantic -std=c++11 student.o main.o Vector.o
student.o: student.cpp student.h
	g++ -Wall -pedantic -std=c++11 -c student.cpp student.h
main.o: main.cpp student.h
	g++ -Wall -pedantic -std=c++11 -c main.cpp student.h
Vector.o: Vector.cpp Vector.h
	g++ -Wall -pedantic -std=c++11 -c Vector.cpp Vector.h
	rm Vector.h.gch student.h.gch
