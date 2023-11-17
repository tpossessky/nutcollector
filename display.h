#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"  

// Function prototypes
void displayHeader();
void displayMainChoices();
void displayGoodbye();
void displayBuyOptions(int prices, int cash, int nuts, int amtCanBuy);
void displaySellOptions(int prices, int cash, int nuts);
void displayDay(int day);
void displayGameInfo(struct Game *game);
void displayGameOver(int win);
void displayError();
void displayEvent(int eventCode);
#endif