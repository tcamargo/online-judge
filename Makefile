CFLAGS=-g -lm -lcrypt
CXX=g++
CC=gcc

.c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@
	
.cpp:
	$(CXX) $(CFLAGS) $@.c -lstdcxx -o $@	

all:	p100 p101 p102 p103 p113 p144

p100:	p100.o
	$(CXX) $(LDFLAGS) -o $@ $<
	
p101:	p101.o
	$(CXX) $(LDFLAGS) -o $@ $<

p102:	p102.o
	$(CXX) $(LDFLAGS) -o $@ $<

p103:	p103.o
	$(CXX) $(LDFLAGS) -o $@ $<
	
p113:	p113.o
	$(CXX) $(LDFLAGS) -o $@ $<	

p144:	p144.o
	$(CXX) $(LDFLAGS) -o $@ $<

clean:
	rm -f *.o p100 p101 p102 p103 p113 p144
