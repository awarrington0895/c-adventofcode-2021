#include <stdio.h>
#include <stdlib.h>
#include "window.h"

void push(int newValue, Window* window) {
  window->values[0] = window->values[1];

  window->values[1] = window->values[2];

  window->values[2] = newValue;
}

int sum(const Window* window) {
  int total = 0;

  for (int i = 0; i < WINDOW_SIZE; i++) {
    total += window->values[i];
  }

  return total;
}

void print(const Window* window) {
  printf("Current Values:");
  
  for (int i = 0; i < WINDOW_SIZE; i++) {
    printf(" %d", window->values[i]);
  }

  printf("\n");
}

Window* newWindow() {
  Window* window = (Window*)malloc(sizeof(Window));
  for (int i = 0; i < WINDOW_SIZE; i++) {
    window->values[i] = 0;
  }

  return window;
}

