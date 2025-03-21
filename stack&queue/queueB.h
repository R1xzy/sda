#ifndef QUEUEB_H
#define QUEUEB_H

#include "amll.h"

// Fungsi Queue (Menggunakan linked list)
void enqueue(Node **front, Node **rear, int value);
int dequeue(Node **front, Node **rear);
void displayQueue(Node *front);

void menu();

#endif  // QUEUE_H
