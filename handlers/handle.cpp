#include "handle.h"

#include <filesystem>
#include <iostream>
#include "sort.h"


void handle_event(SDL_Event &event, AppState &app_state) {
  switch (event.type) {
    case SDL_QUIT:
      app_state.toggleRunning();

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
        case SDLK_b:
          bubbleSort(app_state);
          break;

        case SDLK_m:
          start_mergeSort(app_state);
          break;

        case SDLK_ESCAPE:
          app_state.toggleRunning();
          break;

        case SDLK_SPACE:
          app_state.togglePause();
          break;

        case SDLK_r:
          app_state.reset_data(static_cast<int>(app_state.getData().size()), BUBBLE_SORT);
          break;

        case SDLK_1:
          app_state.setCurrentAlgorithm(BUBBLE_SORT);
          break;

        case SDLK_2:
          app_state.setCurrentAlgorithm(MERGE_SORT);
          break;
      }
  }
}
