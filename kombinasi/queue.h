#ifndef QUEUE_H
#define QUEUE_H

void enqueue(Node **front, Node **rear, int value);
int dequeue(Node **front, Node **rear);
void displayQueue(Node *front);

#endif 
