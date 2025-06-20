//
// Created by daniil on 6/19/25.
//

#include "sort.h"

#include <filesystem>

void bubbleSort(AppState &app_state) {
  int size = static_cast<int>(app_state.getData().size());
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (app_state.getData()[j].value > app_state.getData()[j + 1].value) {
        app_state.swapAndRender(j, j + 1);
      }
    }
    app_state.highlightElement(size - i - 1, {0, 255, 0, 255});
  }

  for (int i = 0; i < size; i++) {
    app_state.highlightElement(i, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(i, {0, 255, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
  }
}

void mergeSort(std::vector<ElementState> &data, int l, int r, AppState &app_state) {
  if (r - l == 1) {
    return;
  }
  int mid = (l + r) / 2;
  mergeSort(data, l, mid, app_state);
  mergeSort(data, mid, r, app_state);
  std::vector<ElementState> cur;

  std::vector<ElementState> left(data.begin() + l, data.begin() + mid);
  std::vector<ElementState> right(data.begin() + mid, data.begin() + r);
  int i = 0, j = 0;
  while (i < left.size() && j < right.size()) {
    app_state.highlightElement(i + l, {255, 0, 0, 255});
    app_state.highlightElement(j + mid, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(i + l, {255, 255, 255, 255});
    app_state.highlightElement(j + mid, {255, 255, 255, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    if (left[i].value < right[j].value) {
      cur.push_back(left[i++]);
    } else {
      cur.push_back(right[j++]);
    }
  }

  while (i < left.size()) {
    app_state.highlightElement(i + l, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(i + l, {255, 255, 255, 255});
    cur.push_back(left[i++]);
  }
  while (j < right.size()) {
    app_state.highlightElement(j + mid, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(j + mid, {255, 255, 255, 255});
    cur.push_back(right[j++]);
  }

  for (int p = l; p < r; p++) {
    app_state.highlightElement(p, {0, 255, 0, 255});
    SDL_Delay(app_state.getDelay());
    app_state.draw_data();
    data[p] = cur[p - l];
    app_state.highlightElement(p, {255, 255, 255, 255});
    SDL_Delay(app_state.getDelay());
    app_state.draw_data();
  }
}

void start_mergeSort(AppState &app_state) {
  int size = static_cast<int>(app_state.getData().size());
  auto &data = app_state.getData();
  mergeSort(data, 0, size, app_state);
  for (int i = 0; i < size; i++) {
    app_state.highlightElement(i, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(i, {0, 255, 0, 255});
    app_state.draw_data();
  }
}

void insertionSort(AppState &app_state) {
  app_state.setDelay(25);
  int size = static_cast<int>(app_state.getData().size());
  app_state.highlightElement(0, {0, 255, 0, 255});
  app_state.draw_data();
  for (int i = 1; i < size; i++) {
    app_state.highlightElement(i, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    for (int j = i - 1; j >= 0; j--) {
      if (app_state.getData()[j].value > app_state.getData()[j + 1].value) {
        app_state.highlightElement(j + 1, {255, 0, 0, 255});
        app_state.draw_data();
        SDL_Delay(app_state.getDelay());
        std::swap(app_state.getData()[j], app_state.getData()[j + 1]);
        app_state.highlightElement(j + 1, {0, 255, 0, 255});
        app_state.highlightElement(j, {0, 255, 0, 255});
        app_state.draw_data();
      } else {
        app_state.highlightElement(j, {0, 255, 0, 255});
        app_state.draw_data();
      }
    }
  }

  for (int i = 0; i < size; i++) {
    app_state.highlightElement(i, {255, 0, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
    app_state.highlightElement(i, {0, 255, 0, 255});
    app_state.draw_data();
    SDL_Delay(app_state.getDelay());
  }
}
