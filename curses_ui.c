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

int create_menu(char *choices[], int n_choices) {
  int highlight = 1;
  int choice = 0;
  int c;
  while (1) {
    print_menu(choices, 3, highlight);
    c = getch();
    switch(c) {
      case 'w':
      case KEY_UP:
        if (highlight == 1) {
          highlight = 3;
        } else {
          highlight--;
        }
        break;
      case 's':
      case KEY_DOWN:
        if (highlight == 3) {
          highlight = 1;
        } else {
          highlight++;
        }
        break;
      case 10:
        choice = highlight;
        break;
    }

    if (choice != 0) return choice;
  }
}

void print_menu(char* choices[], int n_choices, int highlight) {
  int x; 
  int y; 
  x = 2;
  y = 2;
  for(int i = 0; i < n_choices; i++) {
    if (highlight == i + 1) {
      attron(A_REVERSE);
      mvprintw(y, x, "%s", choices[i]);
      attroff(A_REVERSE);
    } else {
      mvprintw(y, x, "%s", choices[i]);
    }
    y++;
  }
  refresh();
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
