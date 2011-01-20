CFLAGS = -g
CXXFLAGS = $(CFLAGS)
CXX = g++
CC = gcc
PROBLEMS = $(patsubst %.c, %, $(wildcard *.c))
PROBLEMS += $(patsubst %.cpp, %, $(wildcard *.cpp))

all: $(PROBLEMS)

.PHONY:	clean
clean:
	rm -f $(PROBLEMS)