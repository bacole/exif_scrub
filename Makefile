CXX ?= g++
FLAGS = -std=c++17 -Wall -Wextra -O2 -I src/

exif_scrub: main.o io.o scrub.o
	$(CXX)  $(FLAGS) -o exif_scrub main.o io.o scrub.o

main.o: main.cpp src/io.h src/scrub.h
	$(CXX)  $(FLAGS) -c main.cpp

io.o: src/io.cpp 
	$(CXX)  $(FLAGS) -c io.cpp

scrub.o: src/scrub.cpp
	$(CXX)  $(FLAGS) -c scrub.cpp