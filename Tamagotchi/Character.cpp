#include "Framework.h"
#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::getAttack(double& damage)
{
	cout << damage << "�� ������!!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}
