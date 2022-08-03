#include "Framework.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::printStatus()
{
	cout << "====================================" << endl;
	cout << "  �̸� : " << name << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "  ���� : " << level << endl;
	cout << "====================================" << endl;
}

void Monster::Attack(Player* _player)
{
	cout << name << "�� �⺻ ����" << endl;
	_player->getAttack(damage);
	Sleep(ONE_SECOND);
}

void Monster::getAttack(int& damage)
{
	hp -= damage;
	checkStatus();
}

bool Monster::checkStatus()
{
	if (hp >= maxHP)
		hp = maxHP;
	else if (hp <= 0)
	{
		hp = 0;
		return true;
	}
	return false;
}
