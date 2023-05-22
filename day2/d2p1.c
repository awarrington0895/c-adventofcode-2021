#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  const int bufferSize = 12;
  char buffer[bufferSize];
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
    printf("%s", buffer);
  }

  printf("\n");
}
