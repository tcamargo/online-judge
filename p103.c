/*   @JUDGE_ID:   6380MH   103   C   ""   */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define IN  "p103.in"
#define OUT "p103.out"

unsigned int box[30][10];

int find_nest(unsigned int *a, unsigned int *b, int unsigned n) {
	int i;
	for(i = 0; i < n; i++)
		if (a[i] >= b[i]) return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	
	unsigned int k, n, i, j, m;
	unsigned int nest, work_nest, previous;
	unsigned int ordered[10];
	unsigned int sequence[10], sequence1[10];
	unsigned int *s, *sw, *tmp;

#ifndef ONLINE_JUDGE
  close (0); open(IN, O_RDONLY);
//  close (1); open(OUT, O_WRONLY | O_CREAT, 0600);
#endif
	while (!feof(stdin)) {
		/* Input read */
	   if (scanf("%u %u\n", &k, &n) == 2) {
         for(i = 0; i < k; i++) {
         	for(j = 0; j < n; j++) {
         		scanf("%u", &box[i][j]);
         	}
            ordered[i] = i;
         }
      } else {
      	break;
      }
      
      
      /* Element sort */
      for(i = 0; i < k; i++) {
      	/* bubble sort */
         for(j = 0; j < n; j++) {
            for(m = j + 1; m < n; m++) {
            	if (box[i][j] > box[i][m]) {
            	   box[i][j] ^= box[i][m];
            	   box[i][m] ^= box[i][j];
            	   box[i][j] ^= box[i][m];
            	}
            }
         }
      }
      
      /* Box sort */
      for(i = 0; i < k; i++) {
      	/* bubble sort */
      	for(m = i + 1; m < k; m++) {
      		if (box[ordered[i]][0] > box[ordered[m]][0]) {
      			ordered[i] ^= ordered[m];
      			ordered[m] ^= ordered[i];
      			ordered[i] ^= ordered[m];
      		}
      	}
      }
      
      /* Find nests */
      nest = 1;
      s  = sequence;
      sw = sequence1;
      for(i = 0; i < k; i++) {
      	work_nest = 1;
      	sw[0] = ordered[i];
      	if ((k - i) < nest) break; /* we already get a good one */
      	previous = ordered[i];
      	/* nests */
      	for(m = i + 1; m < k; m++) {
      		if (find_nest(box[previous],box[ordered[m]],n)) {
      			work_nest++;
      			sw[work_nest - 1] = ordered[m];
      			previous = ordered[m];
      		}
      	}
      	if (work_nest >= nest) {
      		nest = work_nest;
      		tmp = s;  /* save sequence */
      		s  = sw; 
      		sw = tmp;
      	}
      }
            
/*      for(i = 0; i < k; i++) {
         for(j = 0; j < n; j++)
            printf("Box %u Vertex %u = %u\n", i, j, box[i][j]);
      }*/	
      printf("%u\n", nest);
      for(i = 0; i < nest-1; i++)
      	printf("%u ",s[i]+1);
      printf("%u\n",s[i]+1);
            
 	}
	return 0;
}
