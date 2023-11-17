#include "display.h"
#include "functions.h"
#include <windows.h> // Sleep function on Windows


void displayHeader()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    saved_attributes = consoleInfo.wAttributes;

    //make title green 
    SetConsoleTextAttribute(hConsole,
        FOREGROUND_GREEN);

    int delayMicroseconds = 1;
    char text[] =
    "_________________________________________________________________________________________\n"
    "   _______          __    _________        .__  .__                 __                            \n"
    "   \\      \\  __ ___/  |_  \\_   ___ \\  ____ |  | |  |   ____   _____/  |_  ___________         \n"
    "   /   |   \\|  |  \\   __\\ /    \\  \\/ /  _ \\|  | |  | _/ __ \\_/ ___\\   __\\/  _ \\_  __ \\ \n"
    "  /    |    \\  |  /|  |   \\     \\___(  <_> )  |_|  |_\\  ___/\\  \\___|  | (  <_> )  | \\/     \n"
    "  \\____|__  /____/ |__|    \\______  /\\____/|____/____/\\___  >\\___  >__|  \\____/|__|         \n"
    "          \\/                      \\/                      \\/     \\/                           \n"
    "_________________________________________________________________________________________";


    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout); // Flush the output buffer to ensure characters are printed immediately
        Sleep(delayMicroseconds);
    }
    
    printf("\n\nYou are a squirrel! Congrats! You need to get as many nuts as you can before winter\ncomes in 20 days through buying and selling.\n\t-Watch out for other animals though, they're hungry too!");
    printf("\n_________________________________________________________________________________________\n");
    //go back to white text
    SetConsoleTextAttribute(hConsole, saved_attributes);
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    saved_attributes = consoleInfo.wAttributes;

    //make title green 
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
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
    SetConsoleTextAttribute(hConsole, saved_attributes);
}


void displayEvent(int eventCode){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    switch (eventCode){
        case 1:
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\n\n~~Oh No! Another squirrel took some of your nuts~~\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
            printf("\n\n~~Oh No! A hungry bear ate all your nuts~~\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
            printf("\n\n~~Look at that! You found some free nuts on the ground!~~\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
            printf("\n\n~~Look at that! You found some money while climbing a tree!~~\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break;
        case 6:
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
            printf("\n\n~~Oh No! You were eaten by a hawk!!!~~\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(win == 1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\nSQUIRREL HEAVEN!\n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    else {
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("\nWell, not everyone can make it through the winter...\n");
        SetConsoleTextAttribute(hConsole, saved_attributes);

    }
    
}