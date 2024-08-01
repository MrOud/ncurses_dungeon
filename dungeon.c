#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dungeon.h"

void init_room(Dungeon_Room * d) {
  d->dungeon_flags = 0;
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
  int map[DUNGEON_LENGTH][DUNGEON_WIDTH]; //Keep a scratch pad of rooms added
 
  for (int i = 0; i < DUNGEON_LENGTH; i++) {
    for (int j = 0; j < DUNGEON_WIDTH; j++) {
      map[i][j] = 0;
    }
  }

  //Pick a random spot for the first room
  int x_current = 2 + rand() % (DUNGEON_WIDTH - 4);
  int y_current = 2 + rand() % (DUNGEON_LENGTH - 4);
  d->x_coord = x_current;
  d->y_coord = y_current;
  map[y_current][x_current] = 1;

  //add a second room
  
  Dungeon_Room *cur_room;
  d->room_south = malloc(sizeof(Dungeon_Room));
  d->dungeon_flags |= DOOR_SOUTH;
  cur_room = (Dungeon_Room*)d->room_south;
  init_room(cur_room);
  cur_room->x_coord = d->x_coord;
  cur_room->y_coord = d->y_coord + 1;
  map[cur_room->y_coord][cur_room->x_coord] = 2;
  cur_room->room_north = (struct Dungeon_Room*)d;
  cur_room->dungeon_flags |= DOOR_NORTH;
  

  //TESTING: Print map
  printf("Dungeon Map\n----------\n");
  for (int i = 0; i < DUNGEON_LENGTH; i++) {
    for (int j = 0; j < DUNGEON_WIDTH; j++) {
      printf("%d ", map[i][j]);;
    }
    printf("\n");
  }
  printf("\n");
  //d->dungeon_flags = d->dungeon_flags | DOOR_SOUTH | DOOR_EAST;

}
