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

void Dragon::printStatus()
{
	cout << "==============================" << endl;
	cout << "  이름 : " << name << endl;
	cout << "  레벨 : " << level << endl;
	cout << "  체력 : " << hp << endl;
	cout << "==============================" << endl;
}

void Dragon::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "의 브레스 공격!" << endl;
		_player->getAttack(dragon_breath);
	}
	else
	{
		cout << name << "의 기본 공격!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Dragon::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "에게 " << damage << "의 데미지를 입혔다!" << endl;
	if (hp <= 0)
		hp = 0;
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
