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
	cout << "  이름 : " << name   << endl;
	cout << "  체력 : " << hp     << endl;
	cout << "  레벨 : " << level  << endl;
	cout << "데미지 : " << damage << endl;
}

void Character::Attack(Character* _enemy)
{
	int input;
	cout << "1. 기본공격  2. 스킬공격" << endl;
	cin >> input;
	switch (input)
	{
	case 1:		// 기본 공격
		cout << name << "의 기본 공격 !" << endl;
		_enemy->getAttack(damage);
		break;
	case 2:		// 스킬 공격
		cout << name << "의 스킬 공격 !" << endl;
		_enemy->getAttack(skill);
		break;
	}
}

void Character::getAttack(double& damage)
{
	cout << damage << "의 데미지를 받았다!!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}

bool Character::checkStatus()
{
	return false;
}
