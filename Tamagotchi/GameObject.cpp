#include "Framework.h"
#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
    cout << "������ ����Ǿ����ϴ�" << endl;
    delete player;
    delete monster;
}

void GameObject::setPlayerName()
{
    string name;

    cout << "�ٸ���ġ�� �̸��� �����ּ���." << endl;
    cin >> name;

   player = new Player(name);
}

void GameObject::playerAct()
{
    int input = 0;
    while (1)
    {
        cout << "1. �������  2. �İ��ֱ�  3. ���ֱ�  4. �Ʒ�  5. ����  6. ����" << endl;
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
    cout << "����� ���� ���ÿ�.\n 1. ����  2. ����" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "� ���� ����� �� ���ÿ�.\n 1. ���  2. ��Ʈ  3. �巡��" << endl;
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
        cout << "1. �⺻ ����  2. ��ų ����" << endl;
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
        cout << "���� ���" << endl;
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
            cout << "�÷��̾� ���" << endl;
            player->playerLose();
            Sleep(ONE_SECOND);
            system("cls");
            return;
        }
    }
}

