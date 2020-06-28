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

struct point {
    int x;
    int y;
};


struct point Bpoint;
struct point Opoint;
struct point Bdir, Odir;


int cx = (X - 2) / 2 + 1;
int cy = (Y - 2) / 2 + 1;

void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc(int x, int y, char c) {
    mvaddch(y, x, c);
    move(LINES - 1, 1);
    refresh();

}
void gotoxy_puts(int x, int y, char *c) {
    mvaddstr(y, x, c);
    move(LINES - 1, 1);
    refresh();
}
void initfield(int x, int y) {
    mvaddch(0, 0, '0');
    //mvaddch(0, X, 'X');
    gotoxy_putc(X + 2, 0, 'X');
    //mvaddch(Y, 0, 'Y');
    gotoxy_putc(0, Y + 2, 'Y');
    attron(COLOR_PAIR(1));
    for(int i = 1; i <= X; i++) {
        gotoxy_putc(i, 1, '-');
        gotoxy_putc(i, y, '-');
    }
    for(int i = 1; i <= y; i++) {
        gotoxy_putc(1, i, '|');
        gotoxy_putc(X, i, '|');
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    gotoxy_puts(2, Y+ 3, "Message:");
    gotoxy_puts(X + 3, 2, "Help:");
    attroff(COLOR_PAIR(2));

}


void initgame() {
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "终端不支持颜色！\n");
        exit(1);
    }
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    initfield(X, Y);

    Bpoint.x = cx;
    Bpoint.y = Y - 3;
    attron(COLOR_PAIR(3));
    for (int i = 0; i < 8; i++) {
        gotoxy_putc(Bpoint.x + i, Bpoint.y, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.y + 1, ' ');
    }
    attroff(COLOR_PAIR(3));
    refresh();
    

}

void drawgame() {
    gotoxy_putc(Opoint.x, Opoint.y, ' ');

    Opoint.x += Odir.x;
    Opoint.y += Odir.y;

    attron(COLOR_PAIR(2));
    for (int i = 0; i < 8; i++) {
        gotoxy_putc(Bpoint.x + i, Bpoint.y, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.y + 1, ' ');
    }
    attroff(COLOR_PAIR(2));
    Bpoint.x += Bdir.x;
    Bpoint.y += Bdir.y;

    attron(COLOR_PAIR(3));
    for (int i = 0; i < 8; i++) {
        gotoxy_putc(Bpoint.x + i, Bpoint.y, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.y + 1, ' ');
    }
    attroff(COLOR_PAIR(3));

}

#endif
