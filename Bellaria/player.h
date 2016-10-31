#ifndef PLAYER_H	//if PLAYER_H has not been defined
#define PLAYER_H	//Define PLAYER_H

class player{
    private:
        int basedamage = 10;
        int weapondamage = 0;
        int health = 100;
        int maxhealth = 100;
        int currentxp = 0;
        int xpneeded = 100;
        int money = 0;
        int maxmoney = 1000000;
        int majik = 100;
        int maxmajik = 100;
        int playerlevel = 1;

    public:
        player(int maxhealth, int maxmajik);
        ~player(){};
	int levelup();
	int moneycheck();
        int getmoney();
        int gethealth();
        int getdamage();
        int getmajik();
        int getcurrentxp();
        int getmaxhealth();
        int getmaxmajik();
        int getxpneeded();
        int getplayerlevel();
	int gainxp();

};

#endif
