ARCH := $(shell uname)
CXXFLAGS = -g -O2 -pipe
CFLAGS = $(CXXFLAGS) -ansi
LDFLAGS = -lm
ifneq ($(ARCH), Darwin)
	CXX = g++
	CC = gcc
	LDFLAGS += -lcrypt
else
	CXX = llvm-g++
	CC = llvm-gcc
endif
PROBLEMS = $(patsubst %.c, %, $(wildcard *.c))
PROBLEMS += $(patsubst %.cpp, %, $(wildcard *.cpp))

all: $(PROBLEMS)

.PHONY:	clean
clean:
	rm -f $(PROBLEMS)