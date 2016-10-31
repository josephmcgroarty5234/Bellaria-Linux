#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "player.h"

void getplayer();
void playerstats();
void battlescreen();
void textboxdraw();

player* myplayer;

int main(){
	initscr();
	noecho();
	raw();
	keypad (stdscr,true);
	curs_set(0);
	battlescreen();
	return 0;
}
