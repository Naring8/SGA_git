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

void Goblin::printStatus()
{
	cout << "==============================" << endl;
	cout << "  이름 : " << name << endl;
	cout << "  레벨 : " << level << endl;
	cout << "  체력 : " << hp << endl;
	cout << "==============================" << endl;
}

void Goblin::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "의 강한 공격!" << endl;
		_player->getAttack(skill);
	}
	else
	{
		cout << name << "의 기본 공격!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Goblin::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "에게 " << damage << "의 데미지를 입혔다!" << endl;
	if (hp <= 0)
		hp = 0;
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
