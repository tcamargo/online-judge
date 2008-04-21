/*   @JUDGE_ID:   6380MH   101   C++   "Just simple lists manipulations using STL"   */

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
#include <list>
#include <vector>

#define IN  "p101.in"
#define OUT "p101.out"

using namespace std;

/* Class declarations */

class block {
  public:
    int i;
    block(int);
    ~block() {};
};

class pile {
  public:
    int no;
    list <block*> p;
    pile(int);
    ~pile() {};
    void add_block(block*);
    void pop();
};

class world {
  public:
    vector <pile*> w;
    world(int);
    ~world() {};
    void add_pile(pile*);
    pile *find_block(int);
    void move_onto(int, int);
    void move_over(int, int);
    void pile_onto(int, int);
    void pile_over(int, int);
    void quit();
};

/* Class Definitions */

/* Block */
block::block(int n) {
  i = n;
}

/* Pile */

pile::pile(int n) {
  no = n;
  p.clear();
}

void pile::add_block(block *b) {
  p.push_back(b);
}

void pile::pop() {
  p.pop_back();
}

/* World */
world::world(int i) {

  int j;
  pile *pl;

  for(j = 0; j < i; j++) {
    pl = new pile(j);
    pl-> add_block(new block(j));
    add_pile(pl);
  }
}

void world::add_pile(pile* p) {
  w.push_back(p);
}

pile *world::find_block(int b) {

  vector<pile*>::const_iterator iter;
  list<block*>::const_iterator iter2;

  for(iter = w.begin(); iter != w.end(); iter++)
    for(iter2 = (*iter)->p.begin(); iter2 != (*iter)->p.end(); iter2++)
      if ((*iter2)->i == b) return (*iter);

  return (pile *) 0;    /* No warnings!!! :) */
}

void world::move_onto(int a, int b) {

  if (a == b) return;       /* illegal command */

  pile *plb = find_block(b);
  pile *pla = find_block(a);

  if (pla == plb) return;   /* illegal command */

  while ((plb->p.back())->i != b) {
    w[(plb->p.back())->i]->add_block(plb->p.back());
    plb->pop();
  }

  while ((pla->p.back())->i != a) {
    w[(pla->p.back())->i]->add_block(pla->p.back());
    pla->pop();
  }

  w[plb->no]->add_block(pla->p.back());
  pla->pop();
}

void world::move_over(int a, int b) {

  if (a == b) return;       /* illegal command */

  pile *plb = find_block(b);
  pile *pla = find_block(a);

  if (pla == plb) return;   /* illegal command */

  while ((pla->p.back())->i != a) {
    w[(pla->p.back())->i]->add_block(pla->p.back());
    pla->pop();
  }

  w[plb->no]->add_block(pla->p.back());
  pla->pop();
}

void world::quit() {

  vector<pile*>::const_iterator iter;
  list<block*>::const_iterator iter2;
  int i = 0;

  for(iter = w.begin(); iter != w.end(); iter++) {
    printf("%i:", i);
    for(iter2 = (*iter)->p.begin(); iter2 != (*iter)->p.end(); iter2++)
      printf(" %i", (*iter2)->i);
    printf("\n");
    i++;
  }
}

void world::pile_onto(int a, int b) {

  pile *t = new pile(66);

  if (a == b) return;       /* illegal command */

  pile *plb = find_block(b);
  pile *pla = find_block(a);

  if (pla == plb) return;   /* illegal command */

  while ((plb->p.back())->i != b) {
    w[(plb->p.back())->i]->add_block(plb->p.back());
    plb->pop();
  }

  while ((pla->p.back())->i != a) {
    t->add_block(pla->p.back());
    pla->pop();
  }

  t->add_block(pla->p.back());
  pla->pop();

  while (!(t->p.empty())) {
    w[plb->no]->add_block(t->p.back());
    t->pop();
  }
}

void world::pile_over(int a, int b) {

  pile *t = new pile(66);

  if (a == b) return;       /* illegal command */

  pile *plb = find_block(b);
  pile *pla = find_block(a);

  if (pla == plb) return;   /* illegal command */

  while ((pla->p.back())->i != a) {
    t->add_block(pla->p.back());
    pla->pop();
  }

  t->add_block(pla->p.back());
  pla->pop();

  while (!(t->p.empty())) {
    w[plb->no]->add_block(t->p.back());
    t->pop();
  }
}


/* Main program */

int main(int argc, char *argv[]) {

#ifndef ONLINE_JUDGE
  close (0); open(IN, O_RDONLY);
//  close (1); open(OUT, O_WRONLY | O_CREAT, 0600);
#endif

  int np;

  scanf("%i", &np);
  world w(np);

  char s1[5], s2[5];
  int a, b;

  for(;;) {
    scanf("%s %i %s %i", s1, &a, s2, &b);
    if (!strcmp(s1, "quit")) break;
    if (!strcmp(s1, "move"))
      if (!strcmp(s2, "over")) w.move_over(a, b);
    if (!strcmp(s1, "move"))
      if (!strcmp(s2, "onto")) w.move_onto(a, b);
    if (!strcmp(s1, "pile"))
      if (!strcmp(s2, "onto")) w.pile_onto(a, b);
    if (!strcmp(s1, "pile"))
      if (!strcmp(s2, "over")) w.pile_over(a, b);
  }

  w.quit();

  return 0;
}

