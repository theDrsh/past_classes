run: main.o dlist.o tree.o
	g++ -o run main.o dlist.o
tree.o: tree.cpp tree.h tnode.h
	g++ -c -Wall -pedantic -g -std=c++11 tree.cpp
dlist.o: dlist.cpp dlist.h node.h
	g++ -c -Wall -pedantic -g -std=c++11 dlist.cpp
main.o: main.cpp tree.h dlist.h priority_queue.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o tree.o dlist.o run
