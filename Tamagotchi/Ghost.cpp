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


void Ghost::printStatus()
{
	cout << "==============================" << endl;
	cout << "  이름 : " << name << endl;
	cout << "  레벨 : " << level << endl;
	cout << "  체력 : " << hp << endl;
	cout << "==============================" << endl;
}

void Ghost::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "의 힐!" << endl;
		if (hp + heal > 80)
			cout << "체력을 " << (80 - hp) << "만큼 회복했다" << endl;
		else
			cout << "체력을 " << heal << "만큼 회복했다" << endl;
		hp += heal;
		checkStatus();
	}
	else
	{
		cout << name << "의 기본 공격!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Ghost::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "에게 " << damage << "의 데미지를 입혔다!" << endl;
	if (hp <= 0)
		hp = 0;
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
