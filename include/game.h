#ifndef GAME_H
#define GAME_H

typedef struct {
  char answer;
  int bet;
} Bet;

void start_game(const char *username, int *balance);

#endif
