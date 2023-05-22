#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  (void)argc;
  const int bufferSize = 8;
  int increaseCount = 0;
  int currentDepth; 
  int previousDepth; 

  char buffer[bufferSize];
  FILE* inputFile = fopen(argv[1], "r");

  if (inputFile == NULL) {
    printf("Cannot open %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Put first value in previousDepth before looping
  fgets(buffer, bufferSize, inputFile);

  previousDepth = atoi(buffer);

  while (fgets(buffer, bufferSize, inputFile) != NULL) {
    currentDepth = atoi(buffer);

    if (currentDepth > previousDepth) {
      increaseCount++;
    }

    previousDepth = currentDepth;
  }

  fclose(inputFile);

  printf("Depth increased %d times\n", increaseCount);
}
