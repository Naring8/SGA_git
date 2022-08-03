#pragma once
class Player : public Character
{
private:
	string name;
	float  cleanliness = 100.0f;
	float  satiety     = 100.0f;

	int cntWin  = 0;
	int cntLose = 0;

public:
	Player(string _name);
	~Player();

	void Cleaning();
	void  Feeding();
	void Training();

	void initStatus();

	void printStatus() override;

	void Attack(Character* _enemy);
	void skillAttack(Character* _enemy) override;
	void getAttack(double& damage) override;

	bool checkStatus();
	void winEXP(double _exp);

	void  playerWin();
	void playerLose();
	void printScore();
};