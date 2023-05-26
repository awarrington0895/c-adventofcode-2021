#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  (void)argc;

  const int bufferSize = 14;
  char buffer[bufferSize];
  FILE *file = fopen(argv[1], "r");

  int bitCounter[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (fgets(buffer, bufferSize, file) != NULL)
  {
    for (int i = 0; i < 12; i++)
    {
      char currentChar = buffer[i];

      int current = atoi(&currentChar);

      // Determine which bit is most common in a column by incrementing/decrementing
      // array values corresponding to column.  If a particular index value is greater than 0,
      // then 1 is most common.  If bitCounter[i] < 0 most common is 0.
      // This assumes that there is a never a case where they are equally common.
      if (current == 1)
      {
        bitCounter[i]++;
      }
      else
      {
        bitCounter[i]--;
      }
    }
  }

  fclose(file);


  // Binary representation of Epsilon is the inverse
  // of binary representation of Gamma
  int binaryGammaRate[12];
  int binaryEpsilonRate[12];

  printf("GammaRate \t");
  for (int i = 0; i < 12; i++)
  {
    if (bitCounter[i] > 0) {
      binaryGammaRate[i] = 1;
      binaryEpsilonRate[i] = 0;
    } else {
      binaryGammaRate[i] = 0;
      binaryEpsilonRate[i] = 1;
    }
    printf("%d", binaryGammaRate[i]);
  }

  printf("\n");


  printf("EpsilonRate \t");
  for (int i = 0; i < 12; i++) {
    printf("%d", binaryEpsilonRate[i]);
  }

  printf("\n");
}
