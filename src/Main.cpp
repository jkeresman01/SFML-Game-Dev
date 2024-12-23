#include "headers/Game.h"

int main()
{
    snake::Game snakeGame;

    snakeGame.init();
    snakeGame.run();
    snakeGame.shutdown();
}
