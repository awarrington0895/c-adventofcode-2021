#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int depth;
  int position;
} SubmarineLocation;

SubmarineLocation initLocation() {
  SubmarineLocation location = { .depth = 0, .position = 0 };

  return location;
}

SubmarineLocation moveLocation(
  SubmarineLocation location,
  const char* adjustment,
  int adjustmentSize
) {
  // Don't want to mutate the input
  char copy[adjustmentSize];
  strcpy(copy, adjustment);

  // Expected format: DIRECTION<Space>MAGNITUDE
  char* direction = strtok(copy, " ");
  char* magnitudeToken = strtok(NULL, " ");
  int magnitude = atoi(magnitudeToken);

  if (strcmp(direction, "forward") == 0) {
    location.position += magnitude;

    return location;
  }

  if (strcmp(direction, "down") == 0) {
    location.depth += magnitude;

    return location;
  }

  if (strcmp(direction, "up") == 0) {
    location.depth -= magnitude;

    return location;
  }

  printf("WARNING: Encountered unmatched direction: %s", direction);

  return location;
}

void printLocation(const SubmarineLocation* location) {
  printf("Current position = %d\n", location->position);
  printf("Current depth = %d\n\n", location->depth);

  printf("Multiplied = %d\n", location->depth * location->position);
}

int main(int argc, char *argv[]) {
  (void)argc;
  const int bufferSize = 12;
  char buffer[bufferSize];
  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Unable to open file %s", argv[1]);
    return EXIT_FAILURE;
  }

  SubmarineLocation location = initLocation();

  while (fgets(buffer, bufferSize, file) != NULL) {
    location = moveLocation(location, buffer, bufferSize); 
  }

  fclose(file);

  printLocation(&location);
}
