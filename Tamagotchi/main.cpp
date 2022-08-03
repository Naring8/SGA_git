#include "Framework.h"

int main()
{
    GameObject* game = new GameObject;

    game->setPlayerName();
    game->playerAct();

    delete game;

    return 0;
}

