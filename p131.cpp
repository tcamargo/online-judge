#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/types.h>
#include <string.h>

char mao_num[11];
char mao_naipe[10];
char compra_num[5];
char compra_naipe[5];

int compar(const void *a, const void *b) {
	int a1, b1;
	switch(*(char*)a) {
		case 'A': a1 = 1; break;
		case 'T': a1 = 10; break;
		case 'J': a1 = 11; break;
		case 'Q': a1 = 12; break;
		case 'K': a1 = 13; break;
		default:	a1 = *(char*)a & 0x0F;
	}

	switch(*(char*)b) {
		case 'A': b1 = 1; break;
		case 'T': b1 = 10; break;
		case 'J': b1 = 11; break;
		case 'Q': b1 = 12; break;
		case 'K': b1 = 13; break;
		default:	b1 = *(char*)b & 0x0F;
	}

	return a1 - b1; 
}

int avalia(int x) {
	printf("%s\n", mao_num);
	qsort(mao_num, 5+x, sizeof(char), &compar);

	regex_t pair;
	regmatch_t mt;
	size_t n;

	printf("%s\n", mao_num);

	printf("%i\n",regcomp(&pair, "(.)\\1", REG_EXTENDED));	/* par */

	printf("%i\n",regexec(&pair, mao_num, 1, &mt, 0));

	return 0;
}

int main (int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	close(0); open("/home/scm/online-judge/p131.in", O_RDONLY);
//	close(1); open("/home/scm/online-judge/p131.out", O_WRONLY | O_CREAT, 0600);
#endif
	while (1) {
		memset(mao_num, 0, sizeof(mao_num));

		for(int i = 0; i < 5; i++) {
			if (scanf("%c%c ", &mao_num[i], &mao_naipe[i]) < 2)
				return 0;
		}
		
		for(int i = 0; i < 5; i += 1) {
			scanf("%c%c ", &compra_num[i], &compra_naipe[i]);
		}

		scanf("\n");

		int x = 0;	/* cartas a pegar */
		int bestgame = 1; /* highest-card */

		for(int i = 0; i <= 5; i += 1) {
			if (i != 0) {
				mao_num[5+x-1] = compra_num[i-1];	/* compra carta */
				mao_naipe[5+x-1] = compra_naipe[i-1];	/* compra carta */
			}
			int res = avalia(x);
			if (res > bestgame)
				bestgame = res;
			x++;
		}

		char beststr[50];
		switch(bestgame) {
			case 1: sprintf(beststr, "%s", "highest-card"); break;
			case 2: sprintf(beststr, "%s", "one-pair"); break;
			case 3: sprintf(beststr, "%s", "two-pairs"); break;
			case 4: sprintf(beststr, "%s", "three-of-a-kind"); break;
			case 5: sprintf(beststr, "%s", "straight"); break;
			case 6: sprintf(beststr, "%s", "flush"); break;
			case 7: sprintf(beststr, "%s", "full-house"); break;
			case 8: sprintf(beststr, "%s", "four-of-a-kind"); break;
			case 9: sprintf(beststr, "%s", "straight-flush"); break;
		}

		printf("Hand:");
		for(int i = 0; i < 5; i++) {
			printf(" %c%c", mao_num[i], mao_naipe[i]);
		}

		printf(" Deck:");
		for( int i = 0; i < 5; i += 1) {
			printf(" %c%c", compra_num[i], compra_naipe[i]);
		}

		printf(" Best hand: ");
		printf("%s\n", beststr);
//		break;
	}

	return 0;
}
