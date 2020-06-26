/*************************************************************************
	> File Name: game.c
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Jun 2020 02:23:04 PM CST
 ************************************************************************/

#include"game.h" 
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    initgame();


  //  siganl(14, drawgame);

    struct itimerval itimer;
    itimer.it_interval.tv_sec = 10;
    itimer.it_interval.tv_usec = 100000;
    itimer.it_value.tv_sec = 10;
    itimer.it_value.tv_usec = 1000;

    setitimer(ITIMER_REAL, &itimer, NULL);

 /*   while(1) {
       int c = getch();
        switch(c) {
            case KEY_LEFT:
                //
            case KEY_RIGHT:
                //
            default:
            
        }
    }
*/
    getch();
    endwin();
    return 0;
}


