#include "../include/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_balance(const char *username) {
  char filepath[128];
  snprintf(filepath, sizeof(filepath), "data/%s", username);

  FILE *fp = fopen(filepath, "r");
  if (fp) {
    int balance;
    fscanf(fp, "%d", &balance);
    fclose(fp);
    return balance;
  } else {
    FILE *fp_new = fopen(filepath, "w");
    int balance = 100;
    fprintf(fp_new, "%d", balance);
    fclose(fp_new);
    return balance;
  }
}

void save_balance(const char *username, int balance) {
  char filepath[128];
  snprintf(filepath, sizeof(filepath), "data/%s", username);

  FILE *fp = fopen(filepath, "w");
  if (fp) {
    fprintf(fp, "%d", balance);
    fclose(fp);
  }
}
