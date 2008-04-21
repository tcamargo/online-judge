CFLAGS 	-g -Wall -fmessage-length=0
CXX=g++
CC=gcc


 .c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@
	
.cpp:
	$(CXX) $(CFLAGS) $@.c -lstdcxx -o $@	

p100:	p100.c
	$(CXX) $(LDFLAGS) -o $@ $<
	
p101:	p101.cpp
	$(CXX) $(LDFLAGS) -o $@ $<

p103:	p103.c
	$(CXX) $(LDFLAGS) -o $@ $<
	
all:	p103

clean:
	rm -f *.o p100 p101
