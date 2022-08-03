#include "Framework.h"
#include "Ghost.h"


Ghost::Ghost()
{
	name = "고스트";
	hp = 80.0;
	level = 15;
	damage = 13.0;
	exp = 50.0;
	heal = 10.0;
}

Ghost::~Ghost()
{
}

void Ghost::skillAttack(Character* _player)
{
	cout << name << "의 힐 스킬 !" << endl << "(체력 10 회복)" << endl;
	hp += heal;
	checkStatus();

	Sleep(ONE_SECOND);
}

bool Ghost::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "이(가) 쓰러졌다!" << endl << exp << "의 경험치를 받았다!" << endl;
		return true;
	}
	else if (hp >= 80)
		hp = 80;

	return false;
}
