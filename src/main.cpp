#include <SDL2/SDL.h>
#include "init.h"
#include "handle.h"

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow("SortVisualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400,
                                        SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);


  AppState app_state(renderer);
  while (app_state.isRunning()) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      handle_event(event, app_state);
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
