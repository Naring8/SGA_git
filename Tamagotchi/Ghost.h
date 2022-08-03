#pragma once
class Ghost : public Monster
{
public:
	Ghost();
	~Ghost();

	void skillAttack(Character* _player) override;
	//void getAttack(double& damage) override;

	bool checkStatus() override;

private:
	double heal;
};


