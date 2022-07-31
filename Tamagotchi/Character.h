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

	virtual void printStatus();

	virtual void Attack(Character* _enemy);
	virtual void getAttack(double& damage);

	virtual bool checkStatus();

	string getName() { return name; }
	double getdamage() { return damage; }
	double getEXP() { return exp; }
};