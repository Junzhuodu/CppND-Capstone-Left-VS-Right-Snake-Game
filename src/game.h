#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetLeftScore() const;
  int GetLeftSize() const;
  int GetRightScore() const;
  int GetRightSize() const;
  bool GetLeftStatus() const;
  bool GetRightStatus() const;

 private:
  std::vector<std::shared_ptr<Snake>> snakes_;
  std::vector<SDL_Point> foods;
  const int food_sz = 4;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score_left{0};
  int score_right{0};

  bool left_alive = true;
  bool right_alive = true;

  void PlaceFood(SDL_Point &food);
  void Update();
};

#endif