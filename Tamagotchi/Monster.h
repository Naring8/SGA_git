#pragma once
class Monster : public Character
{
protected:

public:
	Monster();
	~Monster();
	virtual void printStatus();
	virtual void Attack(Character* _player) = 0;
	virtual void getAttack(double& damage) = 0;
	virtual bool checkStatus() = 0;
};