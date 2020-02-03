#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  if (!game.GetLeftStatus() && game.GetRightStatus()) {
    std::cout << "Left Snake Touches Viper, Right Snake Wins!" << "\n";
    return 0;
  }
  if (game.GetLeftStatus() && !game.GetRightStatus()) {
    std::cout << "Right Snake Touches Viper, Left Snake Wins!" << "\n";
    return 0;
  }
  std::cout << "Game has terminated successfully!\n";
  std::cout << "ScoreLeft: " << game.GetLeftScore() << "\n";
  std::cout << "SizeLeft: " << game.GetLeftSize() << "\n";
  std::cout << "ScoreRight: " << game.GetRightScore() << "\n";
  std::cout << "SizeRight: " << game.GetRightSize() << "\n";
  if (game.GetLeftScore() > game.GetRightScore()) {
    std::cout << "Left Snake Wins!" << "\n";
  }
  else if (game.GetLeftScore() < game.GetRightScore()) {
    std::cout << "Right Snake Wins!" << "\n";
  }
  else {
    std::cout << "It's a Tie!" << "\n";
  }
  return 0;
}