#include "Framework.h"

Goblin::Goblin()
{
	name = "고블린";
	hp = 20.0;
	level = 1;
	damage = 8.0;
	exp = 35.0;
	skill = damage * 1.5;
}

Goblin::~Goblin()
{
}

void Goblin::skillAttack(Character* _player)
{
	cout << name << "의 스킬 공격 !" << endl;
	_player->getAttack(skill);

	Sleep(ONE_SECOND);
}

bool Goblin::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "이(가) 쓰러졌다!" << endl << exp << "의 경험치를 받았다!" << endl;
		return true;
	}
	return false;
}
