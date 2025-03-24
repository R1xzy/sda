#include "stack.h"

void push(Node **top, int value) {
    insertFirst(top, value);
}

int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack kosong!\n");
        return -1;
    }
    int poppedValue = (*top)->data;
    deleteFirst(top);
    return poppedValue;
}

void displayStack(Node *top) {
    printf("Stack saat ini: ");
    displayList(top);
}
