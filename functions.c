#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int checkInput(int a, int b) {
    return 0;
}

int generateBuyPrices(int day){
    static int tempDay = -1;
    static int dailyPrices = 0;
    
    if(tempDay != day){
        dailyPrices = rand() % 10;
        dailyPrices++;
        tempDay = day;
    }

    return dailyPrices;
}

void generateAmtOfNuts(int day, int *amtOfNuts){
    static int tempDay = -1;
    static int dailyAmt = 0;
    
    if(tempDay != day){
        dailyAmt = rand() % 10;
        tempDay = day;
        *amtOfNuts = dailyAmt;  // Update the value through the pointer

    }

    return;
}

int generateSellPrices(int day){
    static int tempDay = -1;
    static int dailyPrices = 0;
    
    if(tempDay != day){
        dailyPrices = rand() % 10;
        tempDay = day;
    }

    return dailyPrices;
}

int randomEvent(){
    int number;
    number = 5;

    // 20% chance
    int randomNum = rand() % 5 + 1;

    return randomNum == number ? 1 : 0;
}