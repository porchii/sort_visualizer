#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <random>
#include <SDL_rect.h>
#include <vector>

struct ElementState {
  int value;
  SDL_Color color;
};

void generate_array(size_t size, std::vector<ElementState>& array);
#endif
