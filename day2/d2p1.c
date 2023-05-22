#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  (void)argc;
  const int bufferSize = 12;
  char buffer[bufferSize];
  char copy[bufferSize];
  FILE *file = fopen(argv[1], "r");

  if (file == NULL)
  {
    printf("Unable to open file %s", argv[1]);
    return EXIT_FAILURE;
  }

  int currentDepth = 0;
  int currentPosition = 0;

  while (fgets(buffer, bufferSize, file) != NULL)
  {
    strcpy(copy, buffer);

    // Expected format: DIRECTION<Space>MAGNITUDE
    char* direction = strtok(copy, " ");
    char* magnitude = strtok(NULL, " ");

    if (strcmp(direction, "forward") == 0) {
      currentPosition += atoi(magnitude);
      continue;
    }

    if (strcmp(direction, "down") == 0) {
      currentDepth += atoi(magnitude);
      continue;
    }

    if (strcmp(direction, "up") == 0) {
      currentDepth -= atoi(magnitude);
      continue;
    }

    printf("WARNING: Encountered unmatched direction: %s", direction);
  }

  printf("Current position = %d\n", currentPosition);
  printf("Current depth = %d\n\n", currentDepth);

  printf("Multiplied = %d\n", currentDepth * currentPosition);
}
