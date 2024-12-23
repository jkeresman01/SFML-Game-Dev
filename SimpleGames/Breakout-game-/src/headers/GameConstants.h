#pragma once

#include <cstdint>

namespace breakout
{

namespace screen
{
constexpr float HEIGHT = 720.0f;
constexpr float WIDTH = 1280.0f;

constexpr float POSITION_X = 300.0f;
constexpr float POSITION_Y = 200.0f;

} // namespace screen

namespace paddle
{
constexpr float HEIGHT = 20.0f;
constexpr float WIDTH = 100.0f;

constexpr float SPEED = 2.0f;

constexpr float OUTLINE_THICKNESS = 4.0f;

constexpr float POSITION_X = screen::WIDTH / 2 - paddle::WIDTH / 2;
constexpr float POSITION_Y = screen::HEIGHT - 50.0f;
} // namespace paddle

namespace brick
{
constexpr float START_POSTION_X = 10.0f;
constexpr float START_POSTION_Y = 10.0f;

constexpr float HEIGHT = 12.0f;
constexpr float WIDTH = 53.0f;

constexpr float SPACING_X = 10.0f;
constexpr float SPACING_Y = 5.0f;

constexpr float OUTLINE_THICKNESS = 1.0f;

} // namespace brick

namespace ball
{
constexpr float VELOCITY_X_COMPONENT = 1.2;
constexpr float VELOCITY_Y_COMPONENT = 1.2;

constexpr float RADIUS = 10.0f;
} // namespace ball

namespace background
{
constexpr float SCALE_X = 0.7f;
constexpr float SCALE_Y = 0.7f;
} // namespace background

namespace brickwall
{
constexpr uint32_t ROWS = 10;
constexpr uint32_t COLUMNS = 20;
} // namespace brickwall

} // namespace breakout
