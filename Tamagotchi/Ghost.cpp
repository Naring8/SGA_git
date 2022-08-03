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

void Ghost::skillAttack(Character* _player)
{
	cout << name << "�� �� ��ų !" << endl << "(ü�� 10 ȸ��)" << endl;
	hp += heal;
	checkStatus();

	Sleep(ONE_SECOND);
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
