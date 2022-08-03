#pragma once
class Dragon : public Monster
{
public:
	Dragon();
	~Dragon();

	void skillAttack(Character* _player) override;

	bool checkStatus() override;

private:
	double dragon_breath;
};