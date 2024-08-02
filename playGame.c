#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "dungeon.h"
#include "curses_ui.h"


int main(int argc, char *argv[]) {
  Player *player = (Player*)malloc(sizeof(Player));
 // Dungeon_Room *dungeon_root = (Dungeon_Room*)malloc(sizeof(Dungeon_Room));

  init_player(player);
  player_set_name(player, "Spielen");
  init_screen();
  print_player(player);
  getch();
  endwin();
  free(player);

  //init_player(player);
  //player_set_name(player, "Spielen");
  //print_player(player);
  //free(player);

  //printf("\n");

  //Dungeon_Room *dungeon_root = (Dungeon_Room*)malloc(sizeof(Dungeon_Room));
  //init_room(dungeon_root);
  //generate_dungeon(dungeon_root);
  //print_dungeon(dungeon_root);
  //dungeon_root = (Dungeon_Room*)dungeon_root->room_south;
  //print_dungeon(dungeon_root);
  //dungeon_root = (Dungeon_Room*)dungeon_root->room_north;
  //free(dungeon_root->room_south);
  //free(dungeon_root);
  return 0;
}

