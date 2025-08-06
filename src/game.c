#include "../include/game.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_roulette_board() {
  printf("\n================== European Roulette ==================\n");
  printf("[ 0] [ 3] [ 6] [ 9] [12] [15] [18] [21] [24] [27] [30] [33] [36]\n");
  printf("[ 2] [ 5] [ 8] [11] [14] [17] [20] [23] [26] [29] [32] [35]\n");
  printf("[ 1] [ 4] [ 7] [10] [13] [16] [19] [22] [25] [28] [31] [34]\n");
  printf("=======================================================\n\n");
}

void start_game(const char *username, int *balance) {
  srand(time(NULL));

  int balancein = *balance;
  int random, win = 0;
  Bet bets[4] = {0};

  do {
    clear_screen();

    printf("\nWelcome to European Roulette, %s!\n", username);
    printf("Your balance: %d$\n", *balance);
    print_roulette_board();

    random = rand() % 37;

    // BET: specific number
    if (ask_yes_no("Do you want to bet on a specific number?")) {
      do {
        printf("Pick a number from 0 to 36: ");
        scanf("%d", &bets[0].bet);
      } while (bets[0].bet < 0 || bets[0].bet > 36);

      do {
        printf("How much do you want to bet on %d? ", bets[0].bet);
        scanf("%d", &bets[1].bet);
      } while (bets[1].bet <= 0 || bets[1].bet > *balance);

      *balance -= bets[1].bet;
    }

    // BET: even/odd
    if (ask_yes_no("Do you want to bet on EVEN or ODD?")) {
      printf("EVEN or ODD (e/o): ");
      scanf(" %c", &bets[1].answer);

      do {
        printf("How much do you want to bet? ");
        scanf("%d", &bets[2].bet);
      } while (bets[2].bet <= 0 || bets[2].bet > *balance);

      *balance -= bets[2].bet;
    }

    // BET: over/under 18
    if (ask_yes_no("Do you want to bet on numbers > or < 18?")) {
      printf("GREATER (g) or LESS (l): ");
      scanf(" %c", &bets[2].answer);

      do {
        printf("How much do you want to bet? ");
        scanf("%d", &bets[3].bet);
      } while (bets[3].bet <= 0 || bets[3].bet > *balance);

      *balance -= bets[3].bet;
    }

    clear_screen();
    printf("Roulette result: %d\n", random);

    // WINNING CHECKS
    if (random == bets[0].bet) {
      win = bets[1].bet * 35;
      *balance += win;
      printf("🎉 You WON %d$ on number %d!\n", win, bets[0].bet);
    }

    if ((random % 2 == 0 && (bets[1].answer == 'e' || bets[1].answer == 'E')) ||
        (random % 2 != 0 && (bets[1].answer == 'o' || bets[1].answer == 'O'))) {
      win = bets[2].bet * 2;
      *balance += win;
      printf("🎉 You WON %d$ on EVEN/ODD!\n", win);
    }

    if ((random > 18 && (bets[2].answer == 'g' || bets[2].answer == 'G')) ||
        (random < 18 && (bets[2].answer == 'l' || bets[2].answer == 'L'))) {
      win = bets[3].bet * 2;
      *balance += win;
      printf("🎉 You WON %d$ on OVER/UNDER 18!\n", win);
    }

    printf("Your balance: %d$\n", *balance);

    if (*balance <= 0) {
      printf("💸 You are out of money!\n");
      break;
    }

  } while (ask_yes_no("Do you want to play again?"));

  clear_screen();
  printf("🎲 GAME SUMMARY 🎲\n");
  printf("Initial Balance: %d$\nFinal Balance: %d$\n", balancein, *balance);
}
