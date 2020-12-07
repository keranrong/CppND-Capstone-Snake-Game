#include "SDL.h"
#include "wall.h"
#include <cmath>
#include <iostream>

void Walls::Update(Snake &snake, const SDL_Point &food)
{
    SDL_Point newPoint;
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!(CollisionCheck(x, y) || (food.x == x && food.y == y) || snake.SnakeCell(x, y)))
        {
            newPoint.x = x;
            newPoint.y = y;
            std::cout << "new point: x: " << newPoint.x << std::endl;
            std::cout << "new point: y: " << newPoint.y << std::endl;
            wallBody.emplace_back(newPoint);
            return;
        }
    }
}

bool Walls::CollisionCheck(int x, int y)
{
    if (wallBody.empty())
        return false;
    for (auto &p : wallBody)
    {
        if (p.x == x && p.y == y)
        {
            return true;
        }
    }
    return false;
}
bool Walls::CollisionCheck(const Snake &snake)
{
    if (wallBody.empty())
        return false;
    for (auto &p : snake.body)
    {
        if (this->CollisionCheck(p.x, p.y))
        {
            return true;
        }
    }
    return false;
}
