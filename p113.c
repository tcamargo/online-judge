/* Problema 113 do online-judge
 * Power of Cryptography
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main (int argc, char const* argv[]) {

	double n, p, k;


#ifndef ONLINE_JUDGE
	close(0); open("/home/scm/online-judge/p113.in", O_RDONLY);
//	close(1); open("/home/scm/online-judge/p113.out", O_WRONLY | O_CREAT, 0600);
#endif

	while (scanf("%lf\n", &n) == 1) {
		scanf("%lf\n", &p);
		k = exp(log(p)/n);
		printf("%.0f\n", k);

	}
	return 0;
}
