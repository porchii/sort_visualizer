#include "utils.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void generate_array(size_t size, std::vector<ElementState>& array) {
  array.resize(size);
  for (size_t i = 0; i < size; i++) {
    array[i] = {static_cast<int>(rng() % size + 1), {255,255,255,255}};
  }
}
