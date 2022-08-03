#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	void setPlayerName();
	void playerAct();
	void selectMonster();
	void Battle();

private:
	Player* player = nullptr;
	Monster* monster = nullptr;
};
