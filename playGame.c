#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "dungeon.h"

void print_player(Player * p) {
  printf("Player made\n-----\n");
  printf("%s\n", p->name);
  printf("%d / %d hp\n", p->cur_hp, p->max_hp);
  printf("%d / %d sp\n", p->cur_sp, p->max_sp);
  printf("Attack: %d\n", p->attack);
  printf("Defence: %d\n", p->defence);
}

void print_dungeon(Dungeon_Room * d) {
  printf("Dungeon\n--------\n");
  printf("X: %d Y: %d\n", d->x_coord, d->y_coord);
  printf("Status: %d\n", d->dungeon_status);
}

int main(int argc, char *argv[]) {
  Player *player = (Player*)malloc(sizeof(Player));
  init_player(player);
  player_set_name(player, "Spielen");
  print_player(player);
  free(player);

  printf("\n");

  Dungeon_Room *dungeon_root = (Dungeon_Room*)malloc(sizeof(Dungeon_Room));
  init_first_room(dungeon_root);
  generate_dungeon(dungeon_root);
  print_dungeon(dungeon_root);
  free(dungeon_root);
  return 0
  ;
}

