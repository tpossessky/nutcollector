#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Game {
    int nuts;
    int cash;
    int day;
    int dead;
};

// Function prototypes
int checkInput(int a, int b);
int generateBuyPrices(int day);
void generateAmtOfNuts(int day, int *amtOfNuts);
int generateSellPrices(int day);
int randomEvent();

#endif