#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(std::shared_ptr<Snake> snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake->direction != opposite || snake->size == 1) snake->direction = input;
  return;
}

void Controller::HandleInput(bool &running, std::vector<std::shared_ptr<Snake>> &snakes) const {
  SDL_Event e;
  auto snake_left = snakes[0];
  auto snake_right = snakes[1];
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_i:
          ChangeDirection(snake_right, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_k:
          ChangeDirection(snake_right, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_j:
          ChangeDirection(snake_right, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_l:
          ChangeDirection(snake_right, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;

        case SDLK_w:
          ChangeDirection(snake_left, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_s:
          ChangeDirection(snake_left, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_a:
          ChangeDirection(snake_left, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_d:
          ChangeDirection(snake_left, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}