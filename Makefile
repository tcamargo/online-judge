CFLAGS=-g -lm -lcrypt
CXX=g++
CC=gcc

.c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@
	
.cpp:
	$(CXX) $(CFLAGS) $@.c -lstdcxx -o $@	

p100:	p100.o
	$(CXX) $(LDFLAGS) -o $@ $<
	
p101:	p101.o
	$(CXX) $(LDFLAGS) -o $@ $<

p102:	p102.o
	$(CXX) $(LDFLAGS) -o $@ $<

p103:	p103.o
	$(CXX) $(LDFLAGS) -o $@ $<
	
all:	p100 p101 p102 p103

clean:
	rm -f *.o p100 p101 p102 p103
