//
// Created by daniil on 6/19/25.
//

#ifndef SORT_H
#define SORT_H

#include "init.h"

void bubbleSort(AppState& app_state);

void mergeSort(std::vector<ElementState>& data, int l, int r, AppState& app_state);

void start_mergeSort(AppState& app_state);

#endif //SORT_H
