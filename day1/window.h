#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_SIZE 3

typedef struct {
  int values[WINDOW_SIZE];
} Window;

void push(int newValue, Window* window);

int sum(const Window* window);

void print(const Window* window);

Window* newWindow();

#endif
