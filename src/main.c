#include "../include/game.h"
#include "../include/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char username[64];
  int balance = 0;

  printf("Sign-In/Sign-Up\nWrite your Name: ");
  scanf("%63s", username);

  balance = load_balance(username);
  start_game(username, &balance);
  save_balance(username, balance);

  return 0;
}
