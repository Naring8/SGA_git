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

void Goblin::skillAttack(Character* _player)
{
	cout << name << "�� ��ų ���� !" << endl;
	_player->getAttack(skill);

	Sleep(ONE_SECOND);
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
