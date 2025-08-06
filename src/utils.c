#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

void clear_screen() { system(CLEAR_COMMAND); }

int ask_yes_no(const char *prompt) {
  char c;
  printf("%s (y/n): ", prompt);
  scanf(" %c", &c);
  return c == 'y' || c == 'Y';
}
