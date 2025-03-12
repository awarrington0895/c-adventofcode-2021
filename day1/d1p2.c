#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "window.h"

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

  Window* winptr = newWindow();

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
  free(winptr);

  fclose(file);
}
