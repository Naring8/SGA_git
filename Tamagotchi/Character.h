#pragma once
class Character
{
protected:
	string name   = "";
	int    level  = 1;
	double hp     = 0.0;
	double damage = 0.0;
	double skill  = 0.0;
	double exp    = 0.0;

public:
	Character();
	~Character();

	virtual void printStatus() = 0;

	virtual void skillAttack(Character* _enemy) = 0;
	virtual void getAttack(double& damage);


	string getName() { return name; }
	double getdamage() { return damage; }
	double getEXP() { return exp; }
};