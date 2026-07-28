# Compiler and flags
CXX = g++
CXXFLAGS = -O2 -std=gnu++20 -Wall -Wextra -DLOCAL -g

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o *.out a.out $(shell find . -maxdepth 1 -type f -perm -111)

