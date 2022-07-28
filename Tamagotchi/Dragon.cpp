#include "Framework.h"
#include "Dragon.h"

Dragon::Dragon()
{
	name = "�巡��";
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
	cout << "  �̸� : " << name << endl;
	cout << "  ���� : " << level << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "==============================" << endl;
}

void Dragon::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "�� �극�� ����!" << endl;
		_player->getAttack(dragon_breath);
	}
	else
	{
		cout << name << "�� �⺻ ����!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Dragon::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "���� " << damage << "�� �������� ������!" << endl;
	if (hp <= 0)
		hp = 0;
}

bool Dragon::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "��(��) ��������!" << endl << exp << "�� ����ġ�� �޾Ҵ�!" << endl;
		return true;
	}

	return false;
}
