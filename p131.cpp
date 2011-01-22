#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define IN  "p131.in"
#define OUT "p131.out"

class Card {
private:
	std::string card;
	int number;
public:
	Card(std::string c) {
		card = c;
	}
	
	int getnumber() {
		int r;
		
		switch (card[1]) {
			case 'A': r = 1; break;
			case 'T': r = 10; break;
			case 'J': r = 11; break;
			case 'Q': r = 12; break;
			case 'K': r = 13; break;
			default: card[1] >> r;
		}
		return r;
	}
	
	char getsuit() {
		return card[2];
	}
};

int main (int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	close(0); open(IN, O_RDONLY);
	//	close(1); open(OUT, O_WRONLY | O_CREAT, 0600);
#endif
	std::vector<Card> hand;
	std::string line;
	
	while (std::getline(std::cin, line)) {
		std::istringstream linestream(line);
		std::string c;
		while (linestream >> c)
			hand.push_back(c);
		// hand processing
	}
	
//	switch(bestgame) {
//		case 1: sprintf(beststr, "%s", "highest-card"); break;
//		case 2: sprintf(beststr, "%s", "one-pair"); break;
//		case 3: sprintf(beststr, "%s", "two-pairs"); break;
//		case 4: sprintf(beststr, "%s", "three-of-a-kind"); break;
//		case 5: sprintf(beststr, "%s", "straight"); break;
//		case 6: sprintf(beststr, "%s", "flush"); break;
//		case 7: sprintf(beststr, "%s", "full-house"); break;
//		case 8: sprintf(beststr, "%s", "four-of-a-kind"); break;
//		case 9: sprintf(beststr, "%s", "straight-flush"); break;
//	}
	
	return 0;
}
