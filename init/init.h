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
    reset_data(256);
    draw_data();
  };

  explicit AppState(int n);

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

  void reset_data(int n) {
    generate_array(n, data);
    draw_data();
  }

  void setDelay(int ms);
  void toggleRunning() {
    running = !running;
  };

  SDL_Renderer *getRenderer() const { return renderer; }

  bool isRunning() const { return running; }
  int getDelay() const { return delay; }
  std::vector<ElementState> &getData() { return data; }

private:
  int delay = 10;

  bool running = true;
  std::vector<ElementState> data;

  SDL_Renderer *renderer = nullptr;
};

#endif //INIT_H
