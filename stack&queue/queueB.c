#include "queueB.h"

// Fungsi enqueue menggunakan insertLast
void enqueue(Node **front, Node **rear, int value) {
    insertLast(front, value);
    if (*rear == NULL) {
        *rear = *front;
    } else {
        *rear = (*rear)->next;
    }
}

void menu() {
    printf("\n=== Sistem Antrian Bank ===\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Cetak Antrian\n");
    printf("4. Keluar\n");
    printf("Pilihan: ");
}

// Fungsi dequeue menggunakan deleteFirst
int dequeue(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Antrian kosong!\n");
        return -1;  // error jika queue kosong
    }
    int dequeuedValue = (*front)->data;
    deleteFirst(front);
    if (*front == NULL) {
        *rear = NULL;
    }
    return dequeuedValue;
}

// Fungsi menampilkan isi antrian
void displayQueue(Node *front) {
    printf("Antrian saat ini: ");
    displayList(front);
}
