#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <random>
#include <SDL_rect.h>
#include <vector>

enum Algorithm {
  BUBBLE_SORT,
  MERGE_SORT
};

struct ElementState {
  int value;
  SDL_Color color;
};

void generate_array(size_t size, std::vector<ElementState>& array);
#endif
