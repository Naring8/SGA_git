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
	cout << "  이름 : " << name << endl;
	cout << "  레벨 : " << level << endl;
	cout << "  체력 : " << hp << endl;
	cout << "==============================" << endl;
}
