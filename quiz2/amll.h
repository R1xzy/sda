#ifndef AMLL_H  // Macro guard
#define AMLL_H

// Struktur Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// **CREATE**
Node* createNode(int value);
void insertFirst(Node **head, int value);
void insertLast(Node **head, int value);
void insertBetween(Node *prevNode, int value);
void insertBefore(Node **head, int beforeValue, int value);
void insertAfter(Node *head, int afterValue, int value);

// **READ**
void displayList(Node *head);

// **UPDATE**
void updateNode(Node *head, int oldValue, int newValue);

// **DELETE**
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteAfter(Node **head, int afterValue); 
void deleteBefore(Node **head, int beforeValue);
void deleteNode(Node **head, int value);
void destroyList(Node **head);

#endif  
