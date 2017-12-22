//
//  main.cpp
//  PacmanTry1
//
//  Created by abhinav srivastava on 20/12/17.
//  Copyright © 2017 abhinav srivastava. All rights reserved.
//

#include <iostream>
#include <ncurses.h>
#include <string.h>

using namespace std;

static void SpawnPoints(int number)
{
    int tempY;
    int tempX;
    srand(time(NULL));
    for (int c = 0; c<=number-1; c++) {
        tempY = rand() % 23 + 1;
        tempX = rand() % 79 + 1;

        mvprintw(tempY, tempX, ".");
    }
}

static void Boundaries() {
    for (int a = 0; a<=79; a++) {
        mvprintw(0, a, "#");
        mvprintw(23, a, "#");
    }
    for (int b = 0; b<=23; b++) {
        mvprintw(b, 0, "#");
        mvprintw(b, 79, "#");
    }
}

static void InputHandler(int &PacmanXnew, int &PacmanXold, int &PacmanYnew, int &PacmanYold, string &UserInput, int &pointsleft) {
    while (pointsleft != 0) {
        UserInput = getchar();
        if (UserInput == "w") {
            if (mvinch(PacmanYold-1, PacmanXold) == '#') {
                // do nothing and just move on
            }
            else
            {
                if (mvinch(PacmanYold-1, PacmanXold) == '.') {
                    pointsleft--;
                }
                PacmanYnew = PacmanYold - 1;
                mvprintw(PacmanYold, PacmanXold, " ");
                mvprintw(PacmanYnew, PacmanXold, "C");
                refresh();
                PacmanYold = PacmanYnew;
            }
        }
        if (UserInput == "s") {
            if (mvinch(PacmanYold+1, PacmanXold) == '#') {
                // do nothing and just move on
            }
            else
            {
                if (mvinch(PacmanYold+1, PacmanXold) == '.') {
                    pointsleft--;
                }
                PacmanYnew = PacmanYold + 1;
                mvprintw(PacmanYold, PacmanXold, " ");
                mvprintw(PacmanYnew, PacmanXold, "C");
                refresh();
                PacmanYold = PacmanYnew;
            }
        }
        if (UserInput == "d") {
            if (mvinch(PacmanYold, PacmanXold+1) == '#') {
                // do nothing and just move on
            }
            else
            {
                if (mvinch(PacmanYold, PacmanXold+1) == '.') {
                    pointsleft--;
                }
                PacmanXnew = PacmanXold + 1;
                mvprintw(PacmanYold, PacmanXold, " ");
                mvprintw(PacmanYnew, PacmanXnew, "C");
                refresh();
                PacmanXold = PacmanXnew;
            }
            refresh();
        }
        if (UserInput == "a") {
            if (mvinch(PacmanYold, PacmanXold-1) == '#') {
                // do nothing and just move on
            }
            else
            {
                if (mvinch(PacmanYold, PacmanXold-1) == '.') {
                    pointsleft--;
                }
                PacmanXnew = PacmanXold - 1;
                mvprintw(PacmanYold, PacmanXold, " ");
                mvprintw(PacmanYnew, PacmanXnew, "C");
                refresh();
                PacmanXold = PacmanXnew;
            }
            
            
            
        }
        
        
        
    }
    
    if (pointsleft == 0) {
        mvprintw(PacmanYold, PacmanXold, " ");
        mvprintw(1, 38, "YOU WIN!");
    }
}

int main(int argc, const char * argv[]) {
    
    //fdf
    //Added to git
    // initialize the screen
    initscr();
    // set cursor off
    curs_set(0);
    // variable initialization
    int PacmanXnew = 15;
    int PacmanXold = 15;
    int PacmanYnew = 15;
    int PacmanYold = 15;
    int pointsleft = 10;
    string UserInput;
    // print boundaries
    Boundaries();

    // spawn points
    SpawnPoints(pointsleft);

    // print pacman on the screen for the first time
    mvprintw(PacmanYold, PacmanXold, "C");

    refresh();
    
    
    InputHandler(PacmanXnew, PacmanXold, PacmanYnew, PacmanYold, UserInput, pointsleft);

    getch();

    endwin();


    return 0;
}
