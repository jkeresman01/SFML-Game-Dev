#include <gtest/gtest.h>

#include <SFML/System/Vector2.hpp>

#include "../src/headers/GameConstants.h"
#include "../src/headers/Paddle.h"

using namespace breakout;

class PaddleTest : public ::testing::Test
{
  protected:
    Paddle paddle;
};

TEST_F(PaddleTest, AfterPaddleIsCreated_WillPaddlePositionBeInTheMiddle)
{
    EXPECT_EQ(paddle.getPosition().x, screen::WIDTH / 2 - paddle::WIDTH / 2);
}

TEST_F(PaddleTest, AfterPaddleIsMovedToTheRight_WillPaddlePositionXBeGreaterThanBeforeMoveRight)
{
    sf::Vector2f paddlePositionBeforeMoveRight = paddle.getPosition();

    paddle.moveRight();

    sf::Vector2f paddlePositionAfterMoveRight = paddle.getPosition();

    EXPECT_GE(paddlePositionAfterMoveRight.x, paddlePositionBeforeMoveRight.x);
}

TEST_F(PaddleTest, AfterPaddleIsMovedToTheRight_WillPaddlePositionYRemainUnchanged)
{
    sf::Vector2f paddlePositionBeforeMoveRight = paddle.getPosition();

    paddle.moveRight();

    sf::Vector2f paddlePositionAfterMoveRight = paddle.getPosition();

    EXPECT_EQ(paddlePositionAfterMoveRight.y, paddlePositionAfterMoveRight.y);
}

TEST_F(PaddleTest,
       AfterPaddleIsMovedToTheRightAndItsPositionIsOnRightBorder_WillPaddleStayInsideTheBorders)
{
    paddle.setPosition(screen::WIDTH, paddle::POSITION_Y);

    paddle.moveRight();

    EXPECT_EQ(paddle.getPosition().x, screen::WIDTH - paddle::WIDTH);
}

TEST_F(PaddleTest, AfterPaddleIsMovedToTheLeft_WillPaddlePositionXBeMovedToTheLeft)
{
    sf::Vector2f paddlePositionBeforeMoveRight = paddle.getPosition();

    paddle.moveLeft();

    sf::Vector2f paddlePositionAfterMoveRight = paddle.getPosition();

    EXPECT_LE(paddlePositionAfterMoveRight.x, paddlePositionBeforeMoveRight.x);
}

TEST_F(PaddleTest, AfterPaddleIsMovedToTheLeft_WillPaddlePositionYRemainUnchanged)
{
    sf::Vector2f paddlePositionBeforeMoveRight = paddle.getPosition();

    paddle.moveLeft();

    sf::Vector2f paddlePositionAfterMoveRight = paddle.getPosition();

    EXPECT_LE(paddlePositionAfterMoveRight.y, paddlePositionBeforeMoveRight.y);
}

TEST_F(PaddleTest,
       AfterPaddleIsMovedToTheLeftAndItsPositionIsOnLeftBorder_WillPaddleStayInsideTheBorders)
{
    paddle.setPosition(-10, paddle::POSITION_Y);

    paddle.moveLeft();

    EXPECT_EQ(paddle.getPosition().x, 0);
}
