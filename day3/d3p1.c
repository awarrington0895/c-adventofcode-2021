#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../shared/list.h"

/**
 * Calculate decimal number from list of binary bits
 *
 * @param bits Pointer to first element of array containing all bits for binary num
 * @param size Size of bit array
 * @returns Decimal value of bits.  0 if bits is NULL
*/
int binaryToDecimal(int* bits, int size) {
  int result = 0;

  if (bits == NULL) {
    return result;
  }

  int* currentBit = bits;
  
  LinkedList* binary = newList();

  for (int i = 0; i < size; i++) {
    push(*currentBit, binary);
    currentBit++;
  }

  int bit = pop(binary);

  int currentPosition = 0;

  while (bit != -1) {
    if (bit == 0) {
      bit = pop(binary);
      currentPosition++;
      continue;
    }

    result += pow(2, currentPosition);
    currentPosition++;
    bit = pop(binary);
  }

  freeList(binary);

  return result;
}

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

  printf("GammaRate \t\t");
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


  printf("EpsilonRate \t\t");
  for (int i = 0; i < 12; i++) {
    printf("%d", binaryEpsilonRate[i]);
  }

  printf("\n");

  int decimalGammaRate = binaryToDecimal(binaryGammaRate, 12);
  int decimalEpsilonRate = binaryToDecimal(binaryEpsilonRate, 12);

  printf("DecimalGammaRate \t%d\n", decimalGammaRate);
  printf("DecimalEpsilonRate \t%d\n", decimalEpsilonRate);
  printf("PowerConsumption \t%d\n", decimalEpsilonRate * decimalGammaRate);
}
