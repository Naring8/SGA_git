#pragma once
class Dragon : public Monster
{
public:
	Dragon();
	~Dragon();

	void printStatus();
	void Attack(Character* _player);
	void getAttack(double& damage);
	bool checkStatus();

private:
	double dragon_breath;
};



