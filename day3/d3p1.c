#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  (void)argc;

  const int bufferSize = 14;
  char buffer[bufferSize];
  FILE *file = fopen(argv[1], "r");

  int bits[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (fgets(buffer, bufferSize, file) != NULL)
  {
    for (int i = 0; i < 12; i++)
    {
      char currentChar = buffer[i];

      int current = atoi(&currentChar);

      printf("%d", current);
      if (current == 1)
      {
        bits[i]++;
      }
      else
      {
        bits[i]--;
      }
    }
    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < 12; i++)
  {
    printf("%d\n", bits[i]);
  }

  fclose(file);
}
