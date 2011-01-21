/* Problema 113 do online-judge
 * Power of Cryptography
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define IN  "p113.in"
#define OUT "p113.out"

int main (int argc, char const* argv[]) {

	double n, p, k;


#ifndef ONLINE_JUDGE
	close(0); open(IN, O_RDONLY);
    /*	close(1); open(OUT, O_WRONLY | O_CREAT, 0600); */
#endif

	while (scanf("%lf\n", &n) == 1) {
		scanf("%lf\n", &p);
		k = exp(log(p)/n);
		printf("%.0f\n", k);

	}
	return 0;
}
