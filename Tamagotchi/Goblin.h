#pragma once
class Goblin : public Monster
{
public:
	Goblin();
	~Goblin();

	void printStatus();
	void    Attack(Character* _player);
	void getAttack(double& damage);
	bool checkStatus();

private:
	string name;
	double skill;
};