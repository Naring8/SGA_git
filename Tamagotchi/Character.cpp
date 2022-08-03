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
	cout << damage << "의 데미지!!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}
