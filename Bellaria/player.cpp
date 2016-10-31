#include "player.h"




player::player(int maxhealth, int maxmajik){
    this->maxhealth=maxhealth;
    this->maxmajik=maxmajik;
}
int player::gethealth(){

    return health;
}

int player::getdamage(){

    return (basedamage*weapondamage)+basedamage;
}

int player::getmajik(){

    return majik;
}

int player::getcurrentxp(){

    return currentxp;
}

int player::getmoney(){

    return money;
}

int player::getmaxhealth(){

    return maxhealth;
}

int player::getmaxmajik(){

    return maxmajik;
}

int player::getxpneeded(){

    return xpneeded;
}

int player::getplayerlevel(){

    return playerlevel;
}

int player::moneycheck(){

	if (money > maxmoney){
		money = maxmoney;
	}
	return money;
}

int player::levelup(){
	getcurrentxp();
	getxpneeded();
	if (currentxp >= xpneeded){
		playerlevel++;
	}
	return playerlevel;
}

int player::gainxp(){
	currentxp++;
	return currentxp;
}
