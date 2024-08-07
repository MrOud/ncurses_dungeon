#ifndef _curses_ui_h
#define _curses_ui_h

#include "player.h"

void init_screen();
int create_menu(char *choices[], int n_choices);
void print_menu(char *choices[], int n_choices, int highlight);
void print_player(Player* p);

#endif // !_curses_ui_h
