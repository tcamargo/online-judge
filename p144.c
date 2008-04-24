#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char const* argv[]) {

	int N,k;
	int output;
	int qtd;
	int i, nafila;
	char std[25];

#ifndef ONLINE_JUDGE
	close(0); open("/home/scm/online-judge/p144.in", O_RDONLY);
	//close(1); open("/home/scm/online-judge/p144.out", O_WRONLY | O_CREAT, 0600);
#endif
	
	for(;;) {
		scanf("%i %i\n", &N, &k);
		if(N == 0) return 0;

		memset(&std[0], 40, sizeof(std));

		output = 0;
		qtd = 1;
		nafila = N;

		/* */
		do {

			for(  i = 0; i < N; i += 1) {
				if (output == 0) {
					output = qtd++;
					if (qtd > k)
						qtd = 1;
				}

				if (std[i] == -1) continue; /* já saiu da fila */
				if (std[i] - output <= 0) {
					if (output > std[i]) {
						output -= std[i];
					} else {
						output = 0;
					}
					printf("%3i", i+1);
					std[i] = -1;
					nafila--;
				} else {
					std[i] -= output;
					output = 0;
				}
			}
		} while (nafila > 0);
		printf("\n");

		/* */

		
		
	}

	return 0;
}

