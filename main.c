//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/main.c                                                             ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Sat Aug 17 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include <ncurses.h>

int main() {
    int ch;

    // Initialize ncurses
    initscr();
    keypad(stdscr, TRUE); // Enable special key input
    noecho();             // Don't echo input characters

    printw("Press Control-Delete and observe the key code.");

    while ((ch = getch()) != 'q') { // Press 'q' to quit
        printw("\nKey code: %d\n", ch);
        refresh();
    }

    // Clean up and close ncurses
    endwin();
    return 0;
}
