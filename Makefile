CFLAGS = -g -O2 -pipe
CXXFLAGS = $(CFLAGS)
LDFLAGS = -lm -lcrypt
CXX = g++
CC = gcc
PROBLEMS = $(patsubst %.c, %, $(wildcard *.c))
PROBLEMS += $(patsubst %.cpp, %, $(wildcard *.cpp))

all: $(PROBLEMS)

.PHONY:	clean
clean:
	rm -f $(PROBLEMS)