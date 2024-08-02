#include <ncurses.h>
#include "curses_ui.h"
#include "player.h"
#include "dungeon.h"

void init_screen() {
  initscr();
  cbreak();
  curs_set(0);
  noecho();

  keypad(stdscr, TRUE);
}

void print_player(Player * p) {
  printw("Player made\n-----\n");
  printw("%s\n", p->name);
  printw("%d / %d hp\n", p->cur_hp, p->max_hp);
  printw("%d / %d sp\n", p->cur_sp, p->max_sp);
  printw("Attack: %d\n", p->attack);
  printw("Defence: %d\n", p->defence);
}

//void print_dungeon(Dungeon_Room * d) {
//  printf("Dungeon\n--------\n");
//  printf("X: %d Y: %d\n", d->x_coord, d->y_coord);
//  printf("Status: %d\n", d->dungeon_flags);
//  printf("Door N: %d\n", (d->dungeon_flags & DOOR_NORTH));
//  printf("Door S: %d\n", (d->dungeon_flags & DOOR_SOUTH));
//  printf("Door E: %d\n", (d->dungeon_flags & DOOR_EAST));
//  printf("Door W: %d\n", (d->dungeon_flags & DOOR_WEST));
//}
