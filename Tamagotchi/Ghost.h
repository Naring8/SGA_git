#pragma once
class Ghost : public Monster
{
public:
	Ghost();
	~Ghost();

	void printStatus();
	void Attack(Character* _player);
	void getAttack(double& damage);
	bool checkStatus();

private:
	double heal;
};


