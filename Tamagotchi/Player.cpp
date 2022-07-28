#include "Framework.h"
#include "Player.h"

Player::Player(string _name) : name(_name)
{
	damage = 8.0;
	skill = 1.5 * this->damage;
}

Player::~Player()
{
}

void Player::initStatus()
{
	hp = 100.0;
	cleanliness = 100.0f;
	satiety = 100.0f;
}

void Player::printStatus()
{
	cout << "==============================" << endl;
	cout << "  �̸� : " << name << endl;
	cout << "  ü�� : " << hp << endl;
	cout << "  ���� : " << level << endl;
	cout << "û�ᵵ : " << cleanliness << endl;
	cout << "������ : " << satiety << endl;
	cout << "����ġ : " << exp << endl;
	cout << "==============================" << endl;
}

void Player::Cleaning()
{
	cout << "�����ϰ� û�Ҹ� �߽��ϴ�! (û�ᵵ + 10 , ü�� - 5 , ����ġ +10)" << endl;
	cleanliness += 10;
	hp -= 5;
	exp += 10;
	checkStatus();
	printStatus();
}

void Player::Feeding()
{
	cout << "���ִ� ���� �Ծ����ϴ�! (������ +10 , ü�� + 15 , ����ġ +10)" << endl;
	satiety += 10;
	hp += 5;
	exp += 10;
	checkStatus();
	printStatus();
}

void Player::Training()
{
	cout << "���� �Ʒ��� �����ƽ��ϴ�! (û�ᵵ -10 , ������ -10 , ü�� - 15 , ����ġ +30)" << endl;
	cleanliness -= 10;
	satiety -= 10;
	hp -= 15;
	exp += 30;
	checkStatus();
	printStatus();
}

void Player::Attack(Character* _enemy)
{
	int input = 0;
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
	Sleep(1000);
}

void Player::getAttack(double& damage)
{
	cout << name << "��(��) " << damage << "�� �������� �޾Ҵ�!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}

bool Player::checkStatus()
{
	// 1. ü��
	if (hp > 100)
		hp = 100;
	else if (hp <= 0)
	{
		hp = 0;
		cout << name <<"��(��) ����߽��ϴ�..." << endl;
		return true;
	}

	// 2. û�ᵵ
	if (cleanliness > 100)
		cleanliness = 100;
	else if (cleanliness <= 0)
	{
		cleanliness = 0;
		cout << name <<"��(��) ���� �ɷ� ����߽��ϴ�..." << endl;
		return true;
	}

	// 3. ������
	if (satiety > 100)
		satiety = 100;
	else if (satiety <= 0)
	{
		satiety = 0;
		cout << name << "��(��) �谡 ���� ����߽��ϴ�..." << endl;
		return true;
	}

	// 4. ����ġ
	if (exp >= 100)
	{
		exp -= 100;
		level++;
	}
	return false;
}

void Player::winEXP(double _exp)
{
	exp += _exp;
}

void Player::playerWin()
{
	cntWin++;
	printScore();
}

void Player::playerLose()
{
	cntLose++;
	printScore();
}

void Player::printScore()
{
	printf("%2d�� %2d�� %2d��", cntWin + cntLose, cntWin, cntLose);
}