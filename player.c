#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "player.h"

void init_player(Player * p) {
  p->max_hp = 0;
  p->cur_hp = 0;
  p->name[0] = '\0';

  p->attack = 0;
  p->defence = 0;
  p->max_sp = 0;
  p->cur_sp = 0;
}

void player_set_name(Player * p, char name[]) {
  strcpy(p->name, name);
}


