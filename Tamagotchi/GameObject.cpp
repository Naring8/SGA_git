#include "Framework.h"
#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
    cout << "게임이 종료되었습니다" << endl;
    delete player;
    delete monster;
}

void GameObject::setPlayerName()
{
    string name;

    cout << "다마고치의 이름을 정해주세요." << endl;
    cin >> name;

   player = new Player(name);
}

void GameObject::playerAct()
{
    int input = 0;
    while (1)
    {
        cout << "1. 정보출력  2. 씻겨주기  3. 밥주기  4. 훈련  5. 전투  6. 종료" << endl;
        cin >> input;
        system("cls");

        switch (input)
        {
        case 1:
            player->printStatus();
            break;
        case 2:
            player->Cleaning();
            break;
        case 3:
            player->Feeding();
            break;
        case 4:
            player->Training();
            break;
        case 5:
            selectMonster();
            Battle();
            break;
        case 6:
            return;
        default:
            break;
        }
    }
}

void GameObject::selectMonster()
{
    int input = 0;
    cout << "상대할 적을 고르시오.\n 1. 선택  2. 랜덤" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "어떤 적을 상대할 지 고르시오.\n 1. 고블린  2. 고스트  3. 드래곤" << endl;
        cin >> input;
    }
    else
        input = (rand() % 3) + 1;

    switch (input)
    {
    case 1:
        monster = new Goblin;
        break;
    case 2:
        monster = new Ghost;
        break;
    case 3:
        monster = new Dragon;
        break;
    }
}

void GameObject::Battle()
{
    int input = 0;
    player->printStatus();
    monster->printStatus();
    while (1)
    {
        cout << "1. 기본 공격  2. 스킬 공격" << endl;
        cin >> input;

        // Player Attack
        if (input == 1)
        {
            player->Attack(monster);
        }
        else
            player->skillAttack(monster);

       if (monster->checkStatus())
        {
        cout << "몬스터 사망" << endl;
        player->playerWin();
        Sleep(ONE_SECOND);
        system("cls");
        return;
        }

        // Monster Auto Attack
        if (rand() % 4 == 0)
            monster->skillAttack(player);
        else
            monster->Attack(player);

        system("cls");

        player->printStatus();
        monster->printStatus();
        if (player->checkStatus())
        {
            cout << "플레이어 사망" << endl;
            player->playerLose();
            Sleep(ONE_SECOND);
            system("cls");
            return;
        }
    }
}

