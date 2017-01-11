#include "Main.h"
#include "Game.h"

Main::Main()
{

}

Game* Main::createNewGame() {
    Game *g = new Game();
    return g;
}
