#pragma once
class Goblin : public Monster
{
public:
	Goblin();
	~Goblin();

	void skillAttack(Character* _player) override;

	bool checkStatus() override;

private:
	double skill;
};