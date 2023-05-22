#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOW_SIZE 3

typedef struct {
  int values[WINDOW_SIZE];
} Window;

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

int main(int argc, char* argv[]) {
  (void)argc;

  const int bufferSize = 8;
  char buffer[bufferSize];
  FILE* file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Unable to open file with name: %s", argv[1]);
    return EXIT_FAILURE;
  }

  int previousWindowSum;
  int currentWindowSum;
  int currentDepth;
  int increases = 0;

  Window window = { .values = {0, 0, 0 }};
  Window* winptr = &window;

  char* result;
  for (int i = 0; i < WINDOW_SIZE; i++) {
    result = fgets(buffer, bufferSize, file);

    if (result == NULL) {
      printf("Not enough input to build first Window, need at least %d", WINDOW_SIZE);
      return EXIT_FAILURE;
    }

    currentDepth = atoi(buffer);
    push(currentDepth, winptr);
  }

  previousWindowSum = sum(winptr);

  while (fgets(buffer, bufferSize, file) != NULL) {
    currentDepth = atoi(buffer);
    push(currentDepth, winptr);
    currentWindowSum = sum(winptr);

    if (currentWindowSum > previousWindowSum)
      increases++;

    previousWindowSum = currentWindowSum;
  }

  printf("Window increased %d times\n", increases);

  fclose(file);
}
