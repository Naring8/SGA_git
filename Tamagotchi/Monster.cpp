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
	cout << "==============================" << endl;
	cout << "  �̸� : " << name << endl;
	cout << "  ���� : " << level << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "==============================" << endl;
}
