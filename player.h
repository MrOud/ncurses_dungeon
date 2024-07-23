#ifndef _player_h
#define _player_h


typedef struct player {
  //Player stats
  int max_hp;
  int cur_hp;
  char name[21];

  //combat stats
  int attack;
  int defence;
  int max_sp; 
  int cur_sp;

}Player;

void init_player(Player * p);
void player_set_name(Player * p, char name[]);

#endif // !_player_h
#define _player_h

