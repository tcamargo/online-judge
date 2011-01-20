#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define IN  "p103.in"
#define OUT "p103.out"

typedef struct box {
	int d[10];
} box;

void printbox(box ins, int ndim) {
	int i;

	for(i = 0; i < ndim; i++)
		printf("%i ", ins.d[i]);
	printf("\n");
}

int compar(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int nest(const box *a, const box *b, const int dim) {
	int i;

	for(i = 0; i < dim; i++)
		if (a->d[i] >= b->d[i]) return 0;

	return 1;
}

int main(int argc, char *argv[]) {

#ifndef ONLINE_JUDGE
	close (0); open(IN, O_RDONLY);
    /*	close (1); open(OUT, O_WRONLY | O_CREAT, 0600); */
#endif

	int nbox, ndim;
	box instancia[30];
	int matriz[30][30];
	int nestcont[30];
	int i, j;
	int best;
	int nbest;

	int resp[30];
	int respt;

	while (!feof(stdin)) {
		/* instancia */
		if (scanf("%i %i", &nbox, &ndim) != 2) break;
		/* printf("%i caixas com %i dimensoes\n", nbox, ndim); */
		for(i = 0; i < nbox; i++) {
			for(j = 0; j < ndim; j++)
				scanf("%i", &instancia[i].d[j]);
			/* printbox(instancia[i], ndim); */
		}

		/* ordena dimensoes das caixas */
		for(i = 0; i < nbox; i++) {
			qsort(instancia[i].d, ndim, sizeof(int), &compar);
			/* printbox(instancia[i], ndim);*/
		}

		/* constroi matriz de encaixe */
		best = 0;
		for(i = 0; i < nbox; i++) {
			nestcont[i] = 1;
			for(j = 0; j < nbox; j++) {
				if (i==j) {
					matriz[i][j] = 0;
					continue; /* mesma caixa */
				}
				if (nest(&instancia[i], &instancia[j], ndim)) {
					/*printf("%i entra em %i\n", i, j); */
					nestcont[i]++;
					matriz[i][j] = 1;
				} else {
					/*printf("%i nao entra em %i\n", i, j);*/
					matriz[i][j] = 0;
				}

			}
			if (nestcont[best] < nestcont[i])
				best = i;
		}

		/*for(i = 0; i < nbox; i++) {
			for(j = 0; j < nbox; j++) {
				printf("%i ", matriz[i][j]);
			}
			printf("| %i\n", nestcont[i]);
		}*/

		/*printf("melhor %i\n", best);*/
		respt = 0;
		resp[respt++] = best;
		while (nestcont[best] != 1) {
			nbest = -1;
			for(i = 0; i < nbox; i++) {
				if (matriz[best][i] == 1) {
					if ((nbest == -1) || (nestcont[i] > nestcont[nbest]))
						nbest = i;	/* proxima da lista*/
				}
			}
			best = nbest;
			/*printf("melhor %i\n", best);*/
			resp[respt++] = best;
		}

		/* Resposta!!!*/
		printf("%i\n", respt);
		for(i = 0; i < respt; i++)
			if (i == 0)
				printf("%i", resp[i]+1);
			else
				printf(" %i", resp[i]+1);
		printf("\n");


	}

	return 0;
}
