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

void Dragon::skillAttack(Character* _player)
{
	cout << name << "�� ��ų ���� !" << endl;
	_player->getAttack(dragon_breath);

	Sleep(ONE_SECOND);
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
