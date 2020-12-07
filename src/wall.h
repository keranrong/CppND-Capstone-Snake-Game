#ifndef WALLS_H
#define WALLS_H

#include <random>
#include <vector>
#include "SDL.h"
#include "snake.h"
class Snake;

class Walls {
 public:

  Walls(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        random_w(1, static_cast<int>(grid_width)-1),
        random_h(1, static_cast<int>(grid_height)-1) {}

  int size{0};
  void Update(Snake &snake, const SDL_Point &food);

  bool CollisionCheck(int x, int y);
  bool CollisionCheck(const Snake &snake);
  std::vector<SDL_Point> wallBody;

 private:
  int grid_width;
  int grid_height;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif