#include "Framework.h"

Goblin::Goblin()
{
	name = "���";
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
	cout << "  �̸� : " << name << endl;
	cout << "  ���� : " << level << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "==============================" << endl;
}

void Goblin::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "�� ���� ����!" << endl;
		_player->getAttack(skill);
	}
	else
	{
		cout << name << "�� �⺻ ����!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Goblin::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "���� " << damage << "�� �������� ������!" << endl;
	if (hp <= 0)
		hp = 0;
}

bool Goblin::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "��(��) ��������!" << endl << exp << "�� ����ġ�� �޾Ҵ�!" << endl;
		return true;
	}
	return false;
}
