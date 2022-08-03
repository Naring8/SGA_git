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
	cout << "  이름 : " << name << endl;
	cout << "  체력 : " << hp << endl;
	cout << "  레벨 : " << level << endl;
	cout << "====================================" << endl;
}

void Monster::Attack(Player* _player)
{
	cout << name << "의 기본 공격" << endl;
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
