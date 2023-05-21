#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const int bufferSize = 8;
  int increaseCount = 0;
  int currentDepth; 
  int previousDepth; 

  char buffer[bufferSize];
  FILE* inputFile = fopen("day1input.txt", "r");

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
