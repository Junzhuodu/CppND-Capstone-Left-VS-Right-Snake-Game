#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, std::vector<std::shared_ptr<Snake>> &snakes) const;

 private:
  void ChangeDirection(std::shared_ptr<Snake> snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif