#include "headers/Map.h"
#include "headers/Cell.h"
#include "headers/Random.h"

#include <algorithm>
#include <cstring>

namespace gol
{

Map::Map()
{
    for (size_t i = 0; i < ROWS; ++i)
    {
        for (size_t j = 0; j < COLUMNS; ++j)
        {
            float positionX = START_POSITION_X + (j * m_currentGeneration[i][j].getWidth());
            float positionY = START_POSITION_Y + (i * m_currentGeneration[i][j].getHeight());

            m_currentGeneration[i][j].setPosition(positionX, positionY);
            m_nextGeneration[i][j].setPosition(positionX, positionY);
        }
    }
}

void Map::render(sf::RenderWindow &window) const
{
    for (const auto &rows : m_currentGeneration)
    {
        for (const auto &cell : rows)
        {
            cell.render(window);
        }
    }
}

void Map::update()
{
    for (size_t i = 1; i < ROWS - 1; ++i)
    {
        for (size_t j = 1; j < COLUMNS - 1; ++j)
        {
            updateCellState(i, j);
        }
    }

    std::memcpy(m_currentGeneration, m_nextGeneration, sizeof(m_currentGeneration));
    /* m_currentGeneration = m_nextGeneration; */
    /* changeGenerations(); */
}

void Map::updateCellState(uint32_t positionX, uint32_t positionY)
{
    uint32_t aliveNeighbours = countAliveNeighbours(positionX, positionY);

    Cell cell = m_currentGeneration[positionX][positionY];

    if (cell.isAlive() and aliveNeighbours >= OVERPOPULATION or aliveNeighbours < UNDERPOPULATION)
    {
        m_nextGeneration[positionX][positionY].setState(State::DEAD);
    }
    else if (!cell.isAlive() and aliveNeighbours == REPRODUCTION)
    {
        m_nextGeneration[positionX][positionY].setState(State::ALIVE);
    }
    else
    {
        m_nextGeneration[positionX][positionY].setState(cell.getState());
    }
}

uint32_t Map::countAliveNeighbours(uint32_t positionX, uint32_t positionY) const
{
    Cell neighbours[]{
        m_currentGeneration[positionX - 1][positionY],
        m_currentGeneration[positionX + 1][positionY],
        m_currentGeneration[positionX][positionY - 1],
        m_currentGeneration[positionX][positionY + 1],
        m_currentGeneration[positionX - 1][positionY - 1],
        m_currentGeneration[positionX + 1][positionY + 1],
        m_currentGeneration[positionX + 1][positionY - 1],
        m_currentGeneration[positionX - 1][positionY + 1],
    };

    return std::count_if(neighbours, neighbours + NUMBER_OF_NEIGHBOURS,
                         [](const Cell &cell) { return cell.isAlive(); });
}

void Map::changeGenerations()
{
    for (size_t i = 1; i < ROWS - 1; ++i)
    {
        for (size_t j = 1; j < COLUMNS - 1; ++j)
        {
            m_currentGeneration[i][j].setState(m_nextGeneration[i][j].getState());
        }
    }
}

void Map::reshuffle()
{
    for (auto &rows : m_currentGeneration)
    {
        for (auto &cell : rows)
        {
            cell.setState(Random::cellState());
        }
    }
}

} // namespace gol
