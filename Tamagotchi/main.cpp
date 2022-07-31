#include "Framework.h"

int main()
{
    string name;
    int input;

    cout << "다마고치의 이름을 정해주세요." << endl;
    cin >> name;

    Player* player = new Player(name);
    Character* monster = nullptr;
    system("cls");

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
            default:
                break;
            }
            system("cls");
            while (1)
            {
                player->printStatus();
                monster->printStatus();
                if (player->checkStatus())
                {
                    delete monster;

                    player->playerLose();
                    Clear();
                    player->initStatus();
                    break;
                }
                else
                {
                    player->Attack(monster);
                    if (monster->checkStatus())
                    {
                        Clear();
                        player->printStatus();
                        monster->printStatus();
                        
                        player->winEXP(monster->getEXP());
                        player->playerWin();

                        delete monster;
                        Clear();
                        break;
                    }
                    monster->Attack(player);

                    system("cls");
                }
                system("cls");
            }
            break;
        case 6:
            cout << "게임이 종료되었습니다" << endl;
            delete(player);
            return 0;
        default:
            break;
        }
    }
    delete(player);
    delete(monster);

    return 0;
}

