#include "init.h"

AppState::AppState(int n) {
  reset_data(n);
  draw_data();
}


void AppState::draw_data()  {
  SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
  SDL_RenderClear(renderer);

  if (data.empty()) {
    return;
  }

  int width, height;
  SDL_GetRendererOutputSize(renderer, &width, &height);

  int barWidth =  std::max(1, width / static_cast<int>(data.size()));
  int maxVal = std::max_element(data.begin(), data.end(),
    [](const ElementState& a, const ElementState& b) {
      return a.value < b.value;
    }
  )->value;

  for (int i = 0; i < data.size(); ++i) {
    const auto& element = data[i];
    int barHeight = static_cast<int>(element.value * (height - 50) / maxVal);

    SDL_Rect barRect = {
      static_cast<int>(barWidth * i) + (width % barWidth) * 2,
      height - barHeight - 20,
      barWidth - 5,
      barHeight - 1
    };

    SDL_SetRenderDrawColor(renderer, element.color.r, element.color.g, element.color.b, 255);
    SDL_RenderFillRect(renderer, &barRect);
  }

  SDL_RenderPresent(renderer);
}

void AppState::highlightElement(int idx, SDL_Color color) {
  data[idx].color = color;
}

void AppState::setDelay(int ms) {
  delay = ms;
}
