//
// Created by daniil on 6/15/25.
//

#ifndef INIT_H
#define INIT_H
#include <SDL_render.h>
#include <algorithm>
#include <iostream>
#include <SDL_timer.h>

#include "utils.h"


class AppState {
public:
  AppState(SDL_Renderer* renderer): renderer(renderer) {
    reset_data(80, BUBBLE_SORT);
    draw_data();
  };

  explicit AppState(int n, Algorithm alg);

  void draw_data();

  void highlightElement(int idx, SDL_Color color);

  void swapAndRender(int idx1, int idx2) {
    highlightElement(idx1, {255, 0, 0, 255});
    highlightElement(idx2, {255, 0, 0, 255});
    std::swap(data[idx1], data[idx2]);
    draw_data();
    SDL_Delay(delay);
    highlightElement(idx1, {255, 255, 255, 255});
    highlightElement(idx2, {255, 255, 255, 255});
    draw_data();
  }

  void reset_data(int n, Algorithm alg) {
    generate_array(n, data);
    current_algorithm = alg;
    sorting = false;
    paused = false;

    draw_data();
  }

  void setDelay(int ms);

  void startSorting();

  void togglePause() {
    paused = !paused;
  }

  void toggleRunning() {
    running = !running;
  }

  void setCurrentAlgorithm(Algorithm alg) {
    current_algorithm = alg;
  }

  bool isRunning() const { return running; }
  bool isSorting() const { return sorting; }
  bool isPaused() const { return paused; }
  SDL_Renderer *getRenderer() const { return renderer; }
  Algorithm getCurrentAlgorithm() const { return current_algorithm; }

  int getDelay() const { return delay; }
  std::vector<ElementState> &getData() { return data; }

private:
  bool running = true;
  bool sorting = false;
  bool paused = false;

  int delay = 10;

  std::vector<ElementState> data;

  SDL_Renderer *renderer = nullptr;
  Algorithm current_algorithm = MERGE_SORT;
};

#endif //INIT_H
