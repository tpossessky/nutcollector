#include "display.h"
#include "functions.h"


void displayHeader()
{
    printf("________________________________________________________________________________________________\n");
    printf(" _______          __    _________        .__  .__                 __                            \n");
    printf(" \\      \\  __ ___/  |_  \\_   ___ \\  ____ |  | |  |   ____   _____/  |_  ___________         \n");
    printf(" /   |   \\|  |  \\   __\\ /    \\  \\/ /  _ \\|  | |  | _/ __ \\_/ ___\\   __\\/  _ \\_  __ \\ \n");
    printf("/    |    \\  |  /|  |   \\     \\___(  <_> )  |_|  |_\\  ___/\\  \\___|  | (  <_> )  | \\/     \n");
    printf("\\____|__  /____/ |__|    \\______  /\\____/|____/____/\\___  >\\___  >__|  \\____/|__|         \n");
    printf("        \\/                      \\/                      \\/     \\/                           \n");
    printf("________________________________________________________________________________________________\n");
    printf("\nYou are a squirrel! Congrats! You need to store as many nuts as you can before winter comes in 20 days through buying and selling.\n\t-Be careful of the other animals though, they're hungry too!");
    printf("\n________________________________________________________________________________________________\n");

}


void displayMainChoices(){
        printf("What would you like to do: \n\n");
        printf("\t[0] Advance Day\n");
        printf("\t[1] Buy Nuts\n");
        printf("\t[2] Sell Nuts\n");
        printf("\t[3] Stats\n");
        printf("\t[4] Quit\n");

}


void displayGoodbye(){
    printf("\n\n");
    printf("                     ,;:;;,\n");
    printf("                   ;;;;;\n"   );
    printf("           .=',    ;:;;:,\n"  );
    printf("          /_', \"=. ';:;:;\n" );
    printf("          @=:__,  \\,;:;:'\n" );
    printf("            _(\\.=  ;:;;'\n"  );
    printf("           `\"_(  _/=\"`\n"   );
    printf("            `\"'``\n"         );
    printf("         Bye!           \n\n"   );
}


void displayEvent(int eventCode){
    switch (eventCode){
        case 1:
            break;
        case 2:
            printf("\n\n~~Oh No! Another squirrel took some of your nuts~~\n");
            break;
        case 3:
            printf("\n\n~~Oh No! A hungry bear ate all your nuts\n~~");
            break;
        case 4:
            printf("\n\n~~Look at that! You found some free nuts on the ground!~~\n");
            break;
        case 5:
            printf("\n\n~~Look at that! You found some money while climbing a tree!~~\n");
            break;
        case 6:
            printf("\n\n~~Oh No! You were eaten by a hawk!!!~~\n");
            break;
        default:
            break;
    }
}


void displayError(){
    printf("\nYou're nuts! That's not a choice.\n");
}


void displayBuyOptions(int prices, int cash, int nuts, int amtCanBuy){
    printf("----------------------------------------------------------------------\n");
    printf("Daily Nut Price: %d\n", prices);
    printf("Daily Amount of Nuts: %d\n", amtCanBuy);

    printf("-Your Cash $%d\n", cash);
    printf("-Your Nuts %d\n\n", nuts);

    printf("What would you like to do?\n");
    printf("\n\t[0] Buy 1\n");
    printf("\t[1] Buy 5\n");
    printf("\t[2] Buy 10\n");
    printf("\t[3] Exit\n");
}


void displaySellOptions(int prices, int cash, int nuts){
    printf("----------------------------------------------------------------------\n");
    printf("Daily Nut Sell Price: %d\n", prices);
    printf("-Your Cash $%d\n", cash);
    printf("-Your Nuts %d\n\n", nuts);

    printf("What would you like to do?\n");
    printf("\n\t[0] Sell 1\n");
    printf("\t[1] Sell 5\n");
    printf("\t[2] Sell 10\n");
    printf("\t[3] Exit\n");
}


void displayDay(int day){
    printf("\n-----------\n");
    if(day < 10){
        printf("| Day  %d  |\n", day);    
    }else{
        printf("| Day  %d |\n", day);    
    }
    printf("-----------\n");
}


void displayGameInfo(struct Game *game){
    int cash; 
    int nuts; 
    cash = game->cash;
    nuts = game->nuts;

    printf("\n-------------\n");

    if(cash < 10)
        printf("| Cash: $%d  |\n", cash);
    else 
        printf("| Cash: $%d |\n", cash);
    
    if(nuts < 10)
        printf("| Nuts: %d   |\n", nuts);
    else 
        printf("| Nuts: %d  |\n", nuts);

    printf("-------------\n");
}


void displayGameOver(int win){
    if(win == 1)
        printf("\nSQUIRREL HEAVEN!\n");
    else 
        printf("\nWell, not everyone can make it through the winter...\n");
    
}