#include "queue.h"

void menu() {
    printf("\n=== Menu Utama ===\n");
    printf("1. Kelola Linked List\n");
    printf("2. Kelola Stack\n");
    printf("3. Kelola Queue\n");
    printf("4. Keluar\n");
    printf("Pilihan: ");
}

void enqueue(Node **front, Node **rear, int value) {
    insertLast(front, value);
    if (*rear == NULL) {
        *rear = *front;
    } else {
        *rear = (*rear)->next;
    }
}

int dequeue(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Antrian kosong!\n");
        return -1;
    }
    int dequeuedValue = (*front)->data;
    deleteFirst(front);
    if (*front == NULL) {
        *rear = NULL;
    }
    return dequeuedValue;
}

void displayQueue(Node *front) {
    printf("Antrian saat ini: ");
    displayList(front);
}
