#ifndef LIST_H
#define LIST_H

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} LinkedList;

Node* newNode(int);

LinkedList* newList(void);

void push(int, LinkedList*);

int pop(LinkedList*);

void printList(const LinkedList*);

void printNode(const Node*);

void freeList(LinkedList*);

#endif
