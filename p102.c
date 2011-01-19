/*   @JUDGE_ID:   6380MH   102   C   "Brutal Force.. Just 3!"   */

/* -=[ Dark Sky ]-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

   ICQ# 4018498
   mailto: darksky@zaz.com.br
   http://www.inf.ufrgs.br/~camargo

   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define IN  "p102.in"
#define OUT "p102.out"

int main(int argc, char *argv[]) {

  unsigned int b1, g1, c1, b2, g2, c2, b3, g3, c3;
  int mov = -1;
  unsigned int t;
  char c[4] = "TI!";

#ifndef ONLINE_JUDGE
  close (0); open(IN, O_RDONLY);
//  close (1); open(OUT, O_WRONLY | O_CREAT, 0600);
#endif

  while (scanf("%i %i %i %i %i %i %i %i %i", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) == 9) {

    t = b2 + b3 + c1 + c3 + g1 + g2;      /* BCG */
    if (t < mov) {
      mov = t;
      strcpy(c, "BCG");
    }
   
    t = b2 + b3 + c1 + c2 + g1 + g3;      /* BGC */
    if (t < mov) {
      mov = t;
      strcpy(c, "BGC");
    }
   
    t = b1 + b3 + c2 + c3 + g1 + g2;      /* CBG */
    if (t < mov) {
      mov = t;
      strcpy(c, "CBG");
    }
   
    t = b1 + b2 + c2 + c3 + g1 + g3;      /* CGB */
    if (t < mov) {
      mov = t;
      strcpy(c, "CGB");
    }
   
    t = b1 + b3 + c1 + c2 + g2 + g3;      /* GBC */
    if (t < mov) {
      mov = t;
      strcpy(c, "GBC");
    }
   
    t = b1 + b2 + c1 + c3 + g2 + g3;      /* GCB */
    if (t < mov) {
      mov = t;
      strcpy(c, "GCB");
    }
   
    printf("%s %i\n", c, mov);
    mov = -1;
  }

  return 0;
}

