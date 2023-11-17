#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"
#include "display.h"


struct Game game[1];


void buyNuts(){
    int price;
    static int amtOfNuts;
    int choice;
    

    

    price = generateBuyPrices(game->day);
    generateAmtOfNuts(game->day, &amtOfNuts);

    while(1){
        displayBuyOptions(price, game->cash, game->nuts, amtOfNuts);
        scanf("%d", &choice);

        switch (choice)
        {
            //buy 1
            case 0:
                if(amtOfNuts < 1){
                    displayError();
                    break;
                }
                game->cash -= price;
                game->nuts += 1;
                amtOfNuts -= 1;
                break;
            //buy 5
            case 1:
                if(amtOfNuts < 5){
                    displayError();
                    break;
                }
                game->cash -= (price * 5);
                game->nuts += 5;
                amtOfNuts -= 5;

                break;  
            //buy 10      
            case 2:
                if(amtOfNuts < 10){
                    displayError();
                    break;
                }
                game->cash -= (price * 10);
                game->nuts += 10;
                break;
            //leave
            case 3:
                return;
                break;                   
            default:
                displayError();
                return;
                break;
        }

    }
}


void sellNuts(){
    int price;
    int choice;

    price = generateSellPrices(game->day);

    while(1){
        displaySellOptions(price, game->cash, game->nuts);
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                game->cash += price;
                game->nuts -= 1;
                break;
            case 1:
                game->cash += (price * 5);
                game->nuts -= 5;
                break;        
            case 2:
                game->cash += (price * 10);
                game->nuts -= 10;
                break;
            case 3:
                return;
                break;                   
            default:
                displayError();
                return;
                break;
        }

    }
}


void createEvent(){
    int randomNum;
    randomNum = rand() % 5 + 1;

    switch (randomNum){
        case 1:
            displayEvent(randomNum);
            game->cash -= (rand() % 5 + 1);
            break;
        case 2:
            displayEvent(randomNum);
            game->nuts -= (rand() % 5 + 1);
            break;
        case 3:
            displayEvent(randomNum);
            game->nuts = 0;
            break;
        case 4:
            displayEvent(randomNum);
            game->nuts += (rand() % 5 + 1);
            break;
        case 5:
            displayEvent(randomNum);
            game->cash += (rand() % 5 + 1);
            break;
        case 6:
        //crazy rare chance, but you could instantly die
            randomNum = rand() % 40 + 1;

            if(randomNum == 20){
                displayEvent(randomNum);
                game->dead = 1;
            }

            break;
        default:
            break;
    }

}


int endGame(){
    if(game->cash < 0)
        return 1;
    if(game->dead == 1)
        return 1;
    if(game->day == 20)
        return 2;
    return 0; 
}


void run()
{
    int userChoice; 
    int randomEventCheck;  
    int endGameCheck; 

    while(1)
    {   displayDay(game->day);
        displayMainChoices();
        scanf("%d", &userChoice);

        
        switch (userChoice)
        {
            case 0:
                game->day += 1;
                randomEventCheck = randomEvent();

                if(randomEventCheck == 1)
                    createEvent();

                endGameCheck = endGame();
          
                if(endGameCheck == 1){
                    displayGameInfo(game);
                    displayGameOver(0);
                }else if(endGameCheck == 2){
                    displayGameInfo(game);
                    displayGameOver(1);
                }
                break;

            case 1:
                buyNuts();
                break;
            case 2:
                sellNuts();
                break;
            case 3:
                displayGameInfo(game);
                break;
            case 4:
                displayGoodbye();
                return;
                break;
            default:
                displayError();
                break;
        }
    }

}


int main()
{
    srand(time(NULL));

    game->cash = 10;
    game->day = 0;
    game->nuts = 0;
    
    displayHeader();
    run();

   return 0;
}