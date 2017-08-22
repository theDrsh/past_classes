CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

run: minpriority.o graph.o mstapp.o
	$(CXX) $^ -o $@ $(LDFLAGS)

mstapp.o: mstapp.cpp mstapp.h graph.h

graph.o: graph.cpp graph.h minpriority.h
	$(CXX) $(CXXFLAGS) -c $<

minpriority.o: minpriority.cpp minpriority.h 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o run mstapp.o graph.o minpriority.o
