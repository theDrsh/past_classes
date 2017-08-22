CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

run: minpriority.o main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp minpriority.h
	$(CXX) $(CXXFLAGS) -c $<

minpriorityQ.o: minpriority.cpp minpriority.h 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o run minpriority.o main.o
