#ifndef AMLL_H
#define AMLL_H
#include "stack.h"
#include "queue.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fungsi dasar SLL
Node* createNode(int value);
void insertLast(Node **head, int value);
void insertFirst(Node **head, int value);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void displayList(Node *head);
void destroyList(Node **head);

#endif  // AMLL_H
