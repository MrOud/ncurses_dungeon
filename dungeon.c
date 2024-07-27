#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dungeon.h"

void init_first_room(Dungeon_Room * d) {
  d->dungeon_status = 0;
  d->x_coord = 0;
  d->y_coord = 0;
  d->room_north = NULL;
  d->room_south = NULL;
  d->room_east = NULL;
  d->room_west = NULL;
} 

//Requires the 
void generate_dungeon(Dungeon_Room *d) {
  //Guard statements
  if (d->room_north != NULL || d->room_south != NULL ||
      d->room_east != NULL || d->room_west != NULL) return;

  srand(time(NULL)); //Initialize random
  
  int x_current = rand() % DUNGEON_WIDTH + 1;
  int y_current = rand() % DUNGEON_LENGTH + 1;
  d->x_coord = x_current;
  d->y_coord = y_current;
}
