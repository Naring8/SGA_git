#pragma once
class Player : public Character
{
private:
	string name;
	float  cleanliness = 100.0f;
	float  satiety = 100.0f;
	double skill;

	int  cntWin = 0;
	int cntLose = 0;

public:
	Player(string _name);
	~Player();

	void initStatus();

	void printStatus();

	void	Cleaning();
	void	 Feeding();
	void	Training();

	void	  Attack(Character* _enemy);
	void   getAttack(double& damage);

	bool checkStatus();
	void winEXP(double _exp);

	void  playerWin();
	void playerLose();
	void printScore();
};