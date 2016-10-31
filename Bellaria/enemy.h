#ifndef ENEMY_H
#define ENEMY_H

class enemy{
	private:
		int enemydamage;
		int enemyhealth;
		int enemymaxhealth;
	public:
		enemy(int enemyhealthx);
		~enemy()[];
		int xpdropped();
};
#endif
