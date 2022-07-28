#pragma once
class Character
{
protected:
	string name        = "";
	int    level       = 1;
	double hp          = 100.0;
	double exp         = 0.0;
	double damage      = 0.0;

public:
	Character();
	~Character();
	virtual void printStatus() = 0;

	virtual void Attack(Character* _enemy) = 0;
	virtual void getAttack(double& damage) = 0;

	virtual bool checkStatus() = 0;
	string getName() { return name; }
	//double getHP() { return hp; }
	double getdamage() { return damage; }
	double getEXP() { return exp; }
	
};