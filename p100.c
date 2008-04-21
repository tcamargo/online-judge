/*   @JUDGE_ID:   6380MH   100   C   "Dynamic Programming :)"   */

/* -=[ Dark Sky ]-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

   ICQ# 4018498
   mailto: darksky@zaz.com.br
   http://www.inf.ufrgs.br/~camargo

   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define IN  "p100.in"
#define OUT "p100.out"

int main(int argc, char **argv) {

  int i, j, n, n1, s = 0;
  unsigned long long c1, c = 0;

#ifndef ONLINE_JUDGE
  close (0); open(IN, O_RDONLY);
//  close (1); open(OUT, O_WRONLY | O_CREAT, 0600);
#endif

  while (scanf("%i %i", &i, &j) == 2) {
    if (j < i) {   // swap(i, j) :)
      s = 1;
      i ^= j;
      j ^= i;
      i ^= j;
    }
    for (n = i; n <= j; n++) {
      n1 = n;
      c1 = 0;
      c1 = 1;
      while (n1 != 1) {
      c1++;
      if (n1 % 2)
        n1 = 3*n1+1;
      else
        n1 = n1/2;
      }
      c = (c < c1) ? c1 : c;
    }
    if (s)      // Is swaped?
      printf("%i %i %i\n", j, i, c);
    else
      printf("%i %i %i\n", i, j, c);
    c = 1;
    s = 0;
  }

  return 0;
}
