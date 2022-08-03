#include "Framework.h"
#include "Dragon.h"

Dragon::Dragon()
{
	name = "드래곤";
	hp = 150.0;
	level = 35;
	damage = 40.0;
	exp = 150.0;
	dragon_breath = damage * 2.5;
}

Dragon::~Dragon()
{
}

void Dragon::skillAttack(Character* _player)
{
	cout << name << "의 스킬 공격 !" << endl;
	_player->getAttack(dragon_breath);

	Sleep(ONE_SECOND);
}

bool Dragon::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "이(가) 쓰러졌다!" << endl << exp << "의 경험치를 받았다!" << endl;
		return true;
	}

	return false;
}
