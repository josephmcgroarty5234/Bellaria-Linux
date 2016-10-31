#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void moving();
void screeninit();
void charactercreation();
void locationcheck();
void playerstats();
void battlecheck();
void mapdraw();
void randomencounter();
void esteriocity();
void screendraw();
void battlestart();
void playerattset();
void itemshopcheck();

int exitstatus = 0;
int x=2;
int y=3;
int map = 1;

char  maplocation[15];

int maxheight = 40;
int maxwidth = 80;

player* myplayer;// = new player(100, 100);


int main(){
    myplayer=new player(100,100);
    initscr();
    noecho();
    raw();
    keypad (stdscr,true);
    curs_set(0);
do {
    screeninit();
    screendraw();
    refresh();
    moving();   //Code to move the character
    refresh();
} while (exitstatus == 0);
    refresh();
    getch();
    endwin();
    return 0;
}

void screendraw(){
    screeninit();
    refresh();
    mapdraw();
    refresh();
    playerstats();
    locationcheck();
}

void screeninit(){
    if (map == 1) {
        int i = 0;
        int j = 0;
        mvprintw(1,(maxwidth+5),"%s",maplocation);
        do{
        do{
            mvprintw(i,j,".");
            i++;
            }while (i<maxheight);
        j++;
        i=0;
        } while (j<maxwidth);
    }
    else if (map == 2) {
            maxheight = 25;
            maxwidth = 45;
	    refresh();
            int i = 0;
            int j = 0;
            do{
                do{
                mvprintw(i,j,".");
                i++;
                }while (i<maxheight);
            j++;
            i=0;
            }while (j<maxwidth);
            refresh();
    }
}

    //now to make a moveable symbol within the menu
void moving(){
    int movement;
    mvprintw(y,x,"@");
	refresh();
    movement = getch();
    switch(movement){
        case KEY_UP:
            y--;
            randomencounter();
        break;

        case KEY_RIGHT:
            x++;
            randomencounter();
        break;

        case KEY_LEFT:
            x--;
            randomencounter();
        break;

        case KEY_DOWN:
            y++;
            randomencounter();
        break;

        case KEY_BACKSPACE:
            exitstatus = 1;
        break;

        default:
            mvprintw (25,(maxwidth+5),"Try Again...");
            getch();
            mvprintw (25,(maxwidth+5),"             ");
        break;

    } //Ends the switch statement
}

void locationcheck(){

    if (x>(maxwidth-1)){
        x--;
    }

    if (x<0){
        x++;
    }

    if (y>(maxheight-1)){
        y--;
    }

    if (y<0){
        y++;
    }

if (map == 1){
    if (y==10 && x==13){
        maplocation[0]='E';
        maplocation[1]='s';
        maplocation[2]='t';
        maplocation[3]='e';
        maplocation[4]='r';
        maplocation[5]='i';
        maplocation[6]='o';
        maplocation[7]=' ';
        maplocation[8]='C';
        maplocation[9]='i';
        maplocation[10]='t';
        maplocation[11]='y';
        maplocation[12]='\0';
        mvprintw(10,(maxwidth+5),"Press Enter to enter %s",maplocation);
        int entercity;
        entercity = getch();
        switch(entercity){
        case 10:
            esteriocity();
        break;

        default:
            mvprintw(10,maxwidth+5,"                                        ");
    }
    }
    }

    else if (map == 2){
	mapdraw();
	refresh();
        maplocation[0]='B';
        maplocation[1]='e';
        maplocation[2]='l';
        maplocation[3]='l';
        maplocation[4]='a';
        maplocation[5]='r';
        maplocation[6]='i';
        maplocation[7]='a';
        maplocation[8]='\0';
    }
	if (map == 2){
        if (x==10 && y==8){
		itemshopcheck();
	}
	}

}

void mapdraw(){
    refresh();
    if (map==1){ //40x80
    mvprintw(10,13,"E");
    }

    if (map==2) { //25x45
    maxheight = 25;
    maxwidth = 45;
    refresh();
    mvprintw(10,5,"H");
    mvprintw(10,8,"S");

    }
}

void playerstats () {
    if (map==1){
    mvprintw(3,(maxwidth+5),"Hero");
    mvprintw(4,(maxwidth+5), "Health: %d/%d",myplayer->gethealth(),myplayer->getmaxhealth());
    mvprintw(5,(maxwidth+5),"Majik: %d/%d",myplayer->getmajik(),myplayer->getmaxmajik());
    mvprintw(6,(maxwidth+5),"Money: %d",myplayer->getmoney());
    }
}

void battlecheck() {
    if (map==1){
    mvprintw(15,(maxwidth+5),"BATTLE");
    getch();
    mvprintw(15,(maxwidth+5),"      ");
    }
}

void randomencounter(){
    if (map==1){
        int random;
        if (y!=13 && x!=10){
        random = rand() % 100;
        if (random < 10) {
            battlecheck();
        }
        }
    }
}

void esteriocity(){
map=2;
mapdraw();
clear();
mvprintw(1,(maxwidth+5),"Welcome to Esterio City");
mvprintw(3,(maxwidth+5),"Legend:");
mvprintw(4,(maxwidth+5),"H: Hospital");
mvprintw(5,(maxwidth+5),"S: Shop");
locationcheck();
refresh();
}

//Item Shop
void itemshopcheck(){
        refresh();
		mvprintw(7,(maxwidth+5), "Welcome to the item shop");
        refresh();
}
/*
  /\
 /  \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \ \/
 /\ \
/ /\ \
\ \/ /
 \  /
  \/
  
*/