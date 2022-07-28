#include "Framework.h"
#include "Ghost.h"


Ghost::Ghost()
{
	name = "��Ʈ";
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
	cout << "  �̸� : " << name << endl;
	cout << "  ���� : " << level << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "==============================" << endl;
}

void Ghost::Attack(Character* _player)
{
	if (rand() % 4 == 0)
	{
		cout << name << "�� ��!" << endl;
		if (hp + heal > 80)
			cout << "ü���� " << (80 - hp) << "��ŭ ȸ���ߴ�" << endl;
		else
			cout << "ü���� " << heal << "��ŭ ȸ���ߴ�" << endl;
		hp += heal;
		checkStatus();
	}
	else
	{
		cout << name << "�� �⺻ ����!" << endl;
		_player->getAttack(damage);
	}
	Sleep(1000);
}

void Ghost::getAttack(double& damage)
{
	hp -= damage;
	cout << name << "���� " << damage << "�� �������� ������!" << endl;
	if (hp <= 0)
		hp = 0;
}

bool Ghost::checkStatus()
{
	if (hp <= 0)
	{
		hp = 0;
		cout << name << "��(��) ��������!" << endl << exp << "�� ����ġ�� �޾Ҵ�!" << endl;
		return true;
	}
	else if (hp >= 80)
		hp = 80;

	return false;
}
