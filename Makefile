CFLAGS = -g -lm -lcrypt
CXX = g++
CC = gcc
problems = p100 p101 p102 p103 p113 p131 p144

all:	$(problems)

$(problems):
	$(CXX) $(CFLAGS) $@.c* -o $@

.PHONY:	clean
clean:
	rm -f $(problems) *.o 
