#include "Framework.h"
#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::printStatus()
{
	cout << "====================================" << endl;
	cout << "  �̸� : " << name   << endl;
	cout << "  ü�� : " << hp     << endl;
	cout << "  ���� : " << level  << endl;
	cout << "������ : " << damage << endl;
}

void Character::Attack(Character* _enemy)
{
	int input;
	cout << "1. �⺻����  2. ��ų����" << endl;
	cin >> input;
	switch (input)
	{
	case 1:		// �⺻ ����
		cout << name << "�� �⺻ ���� !" << endl;
		_enemy->getAttack(damage);
		break;
	case 2:		// ��ų ����
		cout << name << "�� ��ų ���� !" << endl;
		_enemy->getAttack(skill);
		break;
	}
}

void Character::getAttack(double& damage)
{
	cout << damage << "�� �������� �޾Ҵ�!!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}

bool Character::checkStatus()
{
	return false;
}
