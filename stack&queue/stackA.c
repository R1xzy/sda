#include "stackA.h"

//Implementasi push menggunakan insertFirst
void push(Node **top, int value) {
    insertFirst(top, value);
}

// implementasi pop menggunakan deleteFirst
int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack kosong!\n");
        return -1;  //error jika stack kosong
    }
    int poppedValue = (*top)->data;
    deleteFirst(top);
    return poppedValue;
}

void convertDecimalToBinary(int decimal) {
    Node* stack = NULL;  // Stack kosong

    // Push sisa hasil bagi ke stack
    while (decimal > 0) {
        push(&stack, decimal % 2);
        decimal /= 2;
    }

    // Pop dan cetak hasilnya
    printf("Hasil konversi ke biner: ");
    while (stack != NULL) {
        printf("%d", pop(&stack));
    }
    printf("\n");

    // Bersihkan memori
    destroyList(&stack);
}