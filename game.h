/*************************************************************************
	> File Name: game.h
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Jun 2020 02:23:53 PM CST
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <curses.h>
#define X 70
#define Y 20


void initfield(int x, int y) {
    mvaddch(0, 0, '0');
    mvaddch(0, X, 'X');
    mvaddch(Y, 0, 'Y');

}


void initgame() {
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "终端不支持颜色！\n");
        exit(1);
    }
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    initfield(X, Y);
    refresh();

}

#endif
