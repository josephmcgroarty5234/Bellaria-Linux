#include "player.h"


enemy::enemy(int enemyhealth){
	this->enemyhealth = enemyhealth;
}

int enemy::getehealth(){
	int random = rand() % 1,10;
	return (playerlevel * 100) + random;
}

