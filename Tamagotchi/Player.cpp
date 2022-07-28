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
	cout << "  이름 : " << name << endl;
	cout << "  체력 : " << hp << endl;
	cout << "  레벨 : " << level << endl;
	cout << "청결도 : " << cleanliness << endl;
	cout << "포만감 : " << satiety << endl;
	cout << "경험치 : " << exp << endl;
	cout << "==============================" << endl;
}

void Player::Cleaning()
{
	cout << "깨끗하게 청소를 했습니다! (청결도 + 10 , 체력 - 5 , 경험치 +10)" << endl;
	cleanliness += 10;
	hp -= 5;
	exp += 10;
	checkStatus();
	printStatus();
}

void Player::Feeding()
{
	cout << "맛있는 밥을 먹었습니다! (포만감 +10 , 체력 + 15 , 경험치 +10)" << endl;
	satiety += 10;
	hp += 5;
	exp += 10;
	checkStatus();
	printStatus();
}

void Player::Training()
{
	cout << "힘든 훈련을 끝맞쳤습니다! (청결도 -10 , 포만감 -10 , 체력 - 15 , 경험치 +30)" << endl;
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
	Sleep(1000);
}

void Player::getAttack(double& damage)
{
	cout << name << "이(가) " << damage << "의 데미지를 받았다!" << endl;
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}

bool Player::checkStatus()
{
	// 1. 체력
	if (hp > 100)
		hp = 100;
	else if (hp <= 0)
	{
		hp = 0;
		cout << name <<"이(가) 사망했습니다..." << endl;
		return true;
	}

	// 2. 청결도
	if (cleanliness > 100)
		cleanliness = 100;
	else if (cleanliness <= 0)
	{
		cleanliness = 0;
		cout << name <<"이(가) 병에 걸려 사망했습니다..." << endl;
		return true;
	}

	// 3. 포만감
	if (satiety > 100)
		satiety = 100;
	else if (satiety <= 0)
	{
		satiety = 0;
		cout << name << "이(가) 배가 고파 사망했습니다..." << endl;
		return true;
	}

	// 4. 경험치
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
	printf("%2d전 %2d승 %2d패", cntWin + cntLose, cntWin, cntLose);
}
