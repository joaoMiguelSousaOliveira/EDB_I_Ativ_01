# Makefile 
CC       := gcc
CXX      := g++
CFLAGS   := -Iinclude_c -std=c11 -Wall
CXXFLAGS := -Iinclude_cpp -std=c++17 -Wall

# Make expande os arquivos .c e .cpp
SRCS_C   := $(wildcard src_c/*.c)
SRCS_CPP := $(wildcard src_cpp/*.cpp)

.PHONY: all clean test_c test_cpp

all: test_c test_cpp

test_c:
	$(CC) $(CFLAGS) $(SRCS_C) test_c/test_algorithms.c -o test_c
	./test_c

test_cpp:
	$(CXX) $(CXXFLAGS) $(SRCS_CPP) test_cpp/test_algorithms.cpp -o test_cpp
	./test_cpp

clean:
	rm -f test_c test_cpp
