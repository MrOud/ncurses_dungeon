#ifndef _dungeon_h
#define _dungeon_h

//Dungeon Status
#define DOOR_NORTH 0x1
#define DOOR_SOUTH 0x2
#define DOOR_EAST  0x4
#define DOOR_WEST  0x8

#define ROOM_EXPLORED 0x10
#define HAS_MONSTER   0x20
#define HAS_TREASURE  0x40
#define HAS_EVENT     0x80

//Dungeon Size
#define DUNGEON_WIDTH  10;
#define DUNGEON_LENGTH 10;

typedef struct dungeon_room {
  int dungeon_status; 
  int x_coord;
  int y_coord;
  struct Dungeon_Room * room_north;
  struct Dungeon_Room * room_south;
  struct Dungeon_Room * room_east;
  struct Dungeon_Room * room_west;

} Dungeon_Room;

void init_first_room(Dungeon_Room * d);
void generate_dungeon(Dungeon_Room * d);

#endif // ! dungeon_h 
