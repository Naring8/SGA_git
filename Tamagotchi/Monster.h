#pragma once
class Monster : public Character
{
protected:
	double maxHP = 0;
public:
	Monster();
	~Monster();

	void printStatus() override;

	virtual void Attack(Player* _player);
	virtual void getAttack(int& damage);
	virtual bool checkStatus();
};