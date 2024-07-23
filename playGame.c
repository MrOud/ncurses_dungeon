#include <stdlib.h>
#include <stdio.h>
#include "player.h"

void print_player(Player * p) {
  printf("Player made\n-----\n");
  printf("%s\n", p->name);
  printf("%d / %d hp\n", p->cur_hp, p->max_hp);
  printf("%d / %d sp\n", p->cur_sp, p->max_sp);
  printf("Attack: %d\n", p->attack);
  printf("Defence: %d\n", p->defence);
}

int main(int argc, char *argv[]) {
  Player *player = (Player*)malloc(sizeof(Player));
  init_player(player);
  player_set_name(player, "Spielen");
  print_player(player);
  free(player);
  return 0;
}

