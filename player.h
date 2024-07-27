#ifndef _player_h
#define _player_h

#define NAME_LEN 21

typedef struct player {
  //Player stats
  int max_hp;
  int cur_hp;
  char name[NAME_LEN];

  //combat stats
  int attack;
  int defence;
  int max_sp; 
  int cur_sp;

}Player;

void init_player(Player * p);
void player_set_name(Player * p, char name[]);

#endif // !_player_h

